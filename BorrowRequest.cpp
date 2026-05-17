#include "BorrowRequest.h"
#include "SecurityUtils.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

BorrowRequest::BorrowRequest()
    : requestID_(0), userID_(0), resourceID_(0),
      status_(BorrowRequestStatus::PENDING), identityVerified_(false) {}

void BorrowRequest::createRequest(int requestID, int userID, int resourceID,
                                 const string& requestDate) {
    requestID_ = requestID;
    userID_ = userID;
    resourceID_ = resourceID;
    requestDate_ = requestDate;
    status_ = BorrowRequestStatus::PENDING;
    identityVerified_ = false;
}

void BorrowRequest::approveRequest(const string& approvalDate,
                                   const string& expiryDate) {
    if (status_ != BorrowRequestStatus::PENDING) {
        throw runtime_error("Only pending requests can be approved.");
    }
    approvalDate_ = approvalDate;
    expiryDate_ = expiryDate;
    status_ = BorrowRequestStatus::APPROVED;
}

void BorrowRequest::verifyAndComplete(const string& verificationDate,
                                       const string& verificationMethod) {
    if (status_ != BorrowRequestStatus::APPROVED) {
        throw runtime_error("Only approved requests can be verified.");
    }
    
    if (!isValid(verificationDate)) {
        status_ = BorrowRequestStatus::EXPIRED;
        throw runtime_error("Borrow request has expired. Please request again.");
    }
    
    verificationDate_ = verificationDate;
    verificationMethod_ = verificationMethod;
    identityVerified_ = true;
    status_ = BorrowRequestStatus::VERIFIED;
}

void BorrowRequest::markAsCompleted() {
    if (status_ != BorrowRequestStatus::VERIFIED) {
        throw runtime_error("Only verified requests can be marked as completed.");
    }
    status_ = BorrowRequestStatus::COMPLETED;
}

void BorrowRequest::cancelRequest() {
    if (status_ == BorrowRequestStatus::COMPLETED || status_ == BorrowRequestStatus::CANCELLED) {
        throw runtime_error("Cannot cancel a completed or already cancelled request.");
    }
    status_ = BorrowRequestStatus::CANCELLED;
}

bool BorrowRequest::isValid(const string& currentDate) const {
    if (status_ != BorrowRequestStatus::APPROVED) {
        return false;
    }
    
    // Simple date comparison: if current date is before expiry date, it's valid
    // Format: YYYY-MM-DD
    return currentDate <= expiryDate_;
}

// Getters
int BorrowRequest::getRequestID() const {
    return requestID_;
}

int BorrowRequest::getUserID() const {
    return userID_;
}

int BorrowRequest::getResourceID() const {
    return resourceID_;
}

string BorrowRequest::getRequestDate() const {
    return requestDate_;
}

string BorrowRequest::getApprovalDate() const {
    return approvalDate_;
}

string BorrowRequest::getExpiryDate() const {
    return expiryDate_;
}

string BorrowRequest::getVerificationDate() const {
    return verificationDate_;
}

BorrowRequestStatus BorrowRequest::getStatus() const {
    return status_;
}

string BorrowRequest::getStatusString() const {
    switch (status_) {
        case BorrowRequestStatus::PENDING:
            return "Pending";
        case BorrowRequestStatus::APPROVED:
            return "Approved (24-hour window)";
        case BorrowRequestStatus::VERIFIED:
            return "Identity Verified";
        case BorrowRequestStatus::COMPLETED:
            return "Completed";
        case BorrowRequestStatus::CANCELLED:
            return "Cancelled";
        case BorrowRequestStatus::EXPIRED:
            return "Expired";
        default:
            return "Unknown";
    }
}

string BorrowRequest::getVerificationMethod() const {
    return verificationMethod_;
}

bool BorrowRequest::isIdentityVerified() const {
    return identityVerified_;
}

// Serialization: format: RequestID|UserID|ResourceID|RequestDate|ApprovalDate|ExpiryDate|VerificationDate|Status|VerificationMethod|IdentityVerified
string BorrowRequest::serialize() const {
    stringstream ss;
    ss << requestID_ << "|"
       << userID_ << "|"
       << resourceID_ << "|"
       << requestDate_ << "|"
       << approvalDate_ << "|"
       << expiryDate_ << "|"
       << verificationDate_ << "|"
       << static_cast<int>(status_) << "|"
       << verificationMethod_ << "|"
       << (identityVerified_ ? "1" : "0");
    return ss.str();
}

BorrowRequest* BorrowRequest::deserialize(const string& line) {
    stringstream ss(line);
    string token;
    vector<string> tokens;
    
    while (getline(ss, token, '|')) {
        tokens.push_back(token);
    }
    
    if (tokens.size() < 10) {
        return nullptr;
    }
    
    BorrowRequest* request = new BorrowRequest();
    request->requestID_ = stoi(tokens[0]);
    request->userID_ = stoi(tokens[1]);
    request->resourceID_ = stoi(tokens[2]);
    request->requestDate_ = tokens[3];
    request->approvalDate_ = tokens[4];
    request->expiryDate_ = tokens[5];
    request->verificationDate_ = tokens[6];
    request->status_ = static_cast<BorrowRequestStatus>(stoi(tokens[7]));
    request->verificationMethod_ = tokens[8];
    request->identityVerified_ = (tokens[9] == "1");
    
    return request;
}

void BorrowRequest::displayRequest() const {
    cout << "\n=== Borrow Request Details ===\n";
    cout << "Request ID: " << requestID_ << "\n";
    cout << "User ID: " << userID_ << "\n";
    cout << "Resource ID: " << resourceID_ << "\n";
    cout << "Request Date: " << requestDate_ << "\n";
    cout << "Status: " << getStatusString() << "\n";
    
    if (!approvalDate_.empty()) {
        cout << "Approval Date: " << approvalDate_ << "\n";
        cout << "Valid Until (24-hour window): " << expiryDate_ << "\n";
    }
    
    if (!verificationDate_.empty()) {
        cout << "Verification Date: " << verificationDate_ << "\n";
        cout << "Verification Method: " << verificationMethod_ << "\n";
    }
}
