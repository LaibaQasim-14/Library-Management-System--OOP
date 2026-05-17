#ifndef ADMINANALYTICS_H
#define ADMINANALYTICS_H

#include <string>
#include <vector>
#include <map>
#include <ctime>

class LibraryManager;  // Forward declaration
class UserManager;

struct LibraryStats {
    int totalMembers;
    int activeBorrows;
    int totalResources;
    int availableResources;
    double totalFinesOutstanding;
    double averageFinePerMember;
    int overdueBooks;
    double libraryUtilization;  // Percentage
};

struct PopularBook {
    int resourceID;
    std::string title;
    std::string author;
    int borrowCount;
    double rating;
};

struct MemberActivity {
    int userID;
    std::string username;
    int totalBorrows;
    int activeBorrows;
    double totalFines;
    double latestFine;
    std::string lastBorrowDate;
    std::string membershipExpiry;
};

class AdminAnalytics {
private:
    LibraryManager* libManager_;
    UserManager* userManager_;

public:
    AdminAnalytics(LibraryManager* lm, UserManager* um);

    // Library statistics
    LibraryStats generateLibraryStats() const;
    
    // Popular items
    std::vector<PopularBook> getPopularBooks(int limit = 10) const;
    std::map<std::string, int> getMostBorrowedCategories(int limit = 5) const;
    std::map<std::string, int> getMostBorrowedAuthors(int limit = 5) const;
    
    // Member analytics
    std::vector<MemberActivity> getActiveMembers(int limit = 20) const;
    std::vector<MemberActivity> getMembersWithOverdueBooks() const;
    std::vector<MemberActivity> getHighestFineMembers(int limit = 10) const;
    
    // Time-based analytics
    int getBorrowsInDateRange(const std::string& startDate, const std::string& endDate) const;
    int getReturnsInDateRange(const std::string& startDate, const std::string& endDate) const;
    
    // Fine analytics
    double getTotalOutstandingFines() const;
    double getCollectedFinesInDateRange(const std::string& startDate, const std::string& endDate) const;
    int getOverdueBookCount() const;
    
    // Resource analytics
    double getAverageUtilizationRate() const;
    int getResourcesNeedingMaintenance() const;
    
    // Display methods
    void displayDashboard() const;
    void displayMemberAnalytics() const;
    void displayBookAnalytics() const;
    void displayFineAnalytics() const;
    void displayResourceAnalytics() const;
    
    // Report generation
    std::string generateHTMLReport(const std::string& filename) const;
};

#endif
