#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include "Resource.h"
#include "Usermanager.h"
#include "BorrowRecord.h"
#include "ReportGenerator.h"
#include "Notification.h"
#include "Validator.h"
#include "BorrowRequest.h"

using namespace std;

class LibraryManager {
private:
    vector<Resource*> resources_;
    vector<BorrowRecord*> records_;
    vector<BorrowRequest*> borrowRequests_;  // New: Store borrow requests for physical books
    map<int, vector<int>> waitlist_; // resourceID -> vector of userIDs waiting
    map<int, int> reservations_; // resourceID -> userID reservation holder
    map<int, vector<Notification*>> notifications_; // userID -> notifications
    
    string resourceFilename_;
    string recordFilename_;
    string notificationFilename_;
    string waitlistFilename_;
    string reservationFilename_;
    string borrowRequestFilename_;  // New: Filename for borrow requests
    int nextNotificationID_;

    UserManager& userManager_;
    ReportGenerator& reportGen_;

    void loadResources();
    void saveResources() const;
    void loadRecords();
    void saveRecords() const;
    void loadNotifications();
    void saveNotifications() const;
    void loadWaitlist();
    void saveWaitlist() const;
    void loadReservations();
    void saveReservations() const;
    void loadBorrowRequests();  // New: Load borrow requests
    void saveBorrowRequests() const;  // New: Save borrow requests
    void rebuildBorrowCounts() const;
    void seedSampleResources();
    void addSeedResource(Resource* resource);
    int generateRecordID() const;
    int generateNotificationID();
    int generateBorrowRequestID() const;  // New: Generate request ID
    string toLower(string s) const;
    bool contains(string full, string part) const;

public:
    BorrowRecord* findRecord(int userID, int resourceID) const;
    LibraryManager(UserManager& um, ReportGenerator& rg);

    // Resource management
    void addResource(Resource* res);
    void removeResource(int id);
    void displayAllResources() const;
    void displayAvailableResources() const;
    void saveResourcesToFile() const;
    void displayAllMembersBorrowHistory() const;
    void displayIssuedOrOverdueResourceReport() const;

// Category browsing
    set<string> getAllCategories() const;
    vector<string> getCategories() const;
    void displayCategories() const;
    void displayResourcesByCategory(const string& category) const;

    // Macro category browsing (8 categories)
    vector<string> getMacroCategories() const;
    void displayMacroCategories() const;
    void displayResourcesByMacroCategory(const string& macroCategory) const;

    // Search
    Resource* searchByID(int id) const;
    vector<Resource*> searchByTitle(const string& title) const;
    vector<Resource*> searchByCategory(const string& category) const;

    // Waitlist management
    void addToWaitlist(int userID, int resourceID);
    void removeFromWaitlist(int userID, int resourceID);
    bool isInWaitlist(int userID, int resourceID) const;
    vector<int> getWaitlist(int resourceID) const;
    int getWaitlistPosition(int userID, int resourceID) const;

    void reserveResource(int userID, int resourceID);
    void cancelReservation(int resourceID);
    bool isReserved(int resourceID) const;
    int getReservationHolder(int resourceID) const;

    // Notification management
    void sendNotification(int userID, int resourceID, const string& message, NotificationType type);
    vector<Notification*> getUserNotifications(int userID) const;
    int getUnreadNotificationCount(int userID) const;
    void markNotificationAsRead(int userID, int notificationID);
    void clearNotifications(int userID);
    void displayAllNotifications() const;
    void displayUserNotifications(int userID) const;

    // Borrowing with waitlist support
    void borrowResource(int userID, int resourceID,
                        const string& issueDate,
                        const string& dueDate);

    void returnResource(int userID, int resourceID,
                        const string& returnDate);

    void applyDamageFee(int userID, int resourceID, double damageFee);

    // New: Physical Book Borrow Request System (24-hour verification)
    BorrowRequest* requestBorrowPhysicalBook(int userID, int resourceID, const string& requestDate);
    void approveBorrowRequest(int requestID, const string& approvalDate, int daysValid = 1);
    void verifyAndCompleteBorrow(int requestID, int userID, int resourceID,
                                const string& verificationDate,
                                const string& verificationMethod);
    vector<BorrowRequest*> getPendingBorrowRequests() const;
    vector<BorrowRequest*> getApprovedBorrowRequests() const;
    BorrowRequest* findBorrowRequest(int requestID) const;
    
    // New: Free eBook Access (without borrow record)
    bool accessEBook(int userID, int resourceID, std::string& eBookURL);
    
    // History & reports
    void viewBorrowHistory(int userID) const;
    void generateUserReport(int userID);
    void generateResourceReport(int resourceID);

    // For statistics display
    vector<pair<int, string>> getPendingRequests() const;
    const vector<Resource*>& getResources() const { return resources_; }
    vector<BorrowRecord*> getActiveBorrows() const;

    ~LibraryManager();
};

#endif
