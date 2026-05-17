#ifndef BORROW_REQUEST_H
#define BORROW_REQUEST_H

#include <string>

// Enum for request status
enum class BorrowRequestStatus {
    PENDING = 0,           // Waiting for admin approval
    APPROVED = 1,          // Admin approved, member has 24 hours to visit
    VERIFIED = 2,          // Member visited and admin verified identity
    COMPLETED = 3,         // Borrow completed and record created
    CANCELLED = 4,         // Request cancelled by member or admin
    EXPIRED = 5            // 24-hour window expired without verification
};

class BorrowRequest {
private:
    int requestID_;
    int userID_;
    int resourceID_;
    std::string requestDate_;
    std::string approvalDate_;
    std::string expiryDate_;        // 24 hours from approval
    std::string verificationDate_;
    BorrowRequestStatus status_;
    std::string verificationMethod_;  // "USERNAME", "CNIC", "PHONE"
    bool identityVerified_;

public:
    BorrowRequest();
    
    // Create a new borrow request
    void createRequest(int requestID, int userID, int resourceID,
                      const std::string& requestDate);
    
    // Approve request by admin (sets expiry to 24 hours from now)
    void approveRequest(const std::string& approvalDate, const std::string& expiryDate);
    
    // Verify member identity and complete borrow
    void verifyAndComplete(const std::string& verificationDate, 
                          const std::string& verificationMethod);
    
    // Mark as completed
    void markAsCompleted();
    
    // Cancel the request
    void cancelRequest();
    
    // Check if request is still valid (not expired)
    bool isValid(const std::string& currentDate) const;
    
    // Getters
    int getRequestID() const;
    int getUserID() const;
    int getResourceID() const;
    std::string getRequestDate() const;
    std::string getApprovalDate() const;
    std::string getExpiryDate() const;
    std::string getVerificationDate() const;
    BorrowRequestStatus getStatus() const;
    std::string getStatusString() const;
    std::string getVerificationMethod() const;
    bool isIdentityVerified() const;
    
    // Serialization
    std::string serialize() const;
    static BorrowRequest* deserialize(const std::string& line);
    
    // Display
    void displayRequest() const;
};

#endif
