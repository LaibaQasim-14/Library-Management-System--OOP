#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

// Admin roles for role-based access control
enum class AdminRole {
    ADMIN,              // Standard admin - can process borrow/return and view resources
    SUPER_ADMIN,        // Super admin - highest privileges and can manage all admin duties
    LIBRARIAN,          // Librarian - resource addition / removal / update tasks
    NOTIFICATION_ADMIN, // Handles notifications and communication tasks
    FINE_MANAGER        // Handles fines, adjustments, and financial status
};

class Admin : public User {
private:
    AdminRole roleType_;
    bool isActive_;          // For suspension
    std::string createdAt_;
    std::string lastLogin_;

public:
    Admin(int id, std::string username, std::string password,
          std::string first, std::string last, std::string email,
          std::string cnic, std::string phone, std::string address,
          double balance,
          AdminRole role = AdminRole::ADMIN);

    // Profile display
    void displayProfile() const override;
    void displayFullProfile() const;  // Full profile for admin viewing
    std::string serialize() const override;

    // Deserialization
    static Admin* deserialize(const std::string& line);

    // Privilege management
    void setPrivilegeLevel(AdminRole role);
    AdminRole getPrivilegeLevel() const;
    std::string getAdminRoleName() const;
    bool hasSuperAdminPrivilege() const;
    bool canManageMembers() const;
    bool canManageAdmins() const;
    bool canManageResources() const;
    bool canManageNotifications() const;
    bool canManageFines() const;

    // Account status management
    void suspend();
    void reinstate();
    bool isActive() const;
    
    // Timestamps
    void updateLastLogin();
    std::string getCreatedAt() const;
    std::string getLastLogin() const;
    
    // Security check
    bool isPasswordSecure() const;
    void changePassword(const std::string& oldPassword, const std::string& newPassword);
};

#endif
