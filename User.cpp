#include "User.h"
#include "SYSTEMEXCEPTIONS.h"
#include "Validator.h"
#include "SecurityUtils.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace {
bool isStoredPasswordHash(const string& password)
{
    const size_t separator = password.find(':');
    if (separator == string::npos)
        return false;

    const string salt = SecurityUtils::extractSalt(password);
    const string hash = SecurityUtils::extractHash(password);

    if (salt.empty() || hash.length() != 64)
        return false;

    return all_of(hash.begin(), hash.end(), [](unsigned char c) {
        return isxdigit(c) != 0;
    });
}

void validateStoredPassword(const string& password)
{
    if (isStoredPasswordHash(password))
        return;

    Validator::validatePassword(password);
}
}

User::User(int id, string username, string password,
           string first, string last, string email,
           string cnic, string phone, string address, double balance)
{
    Validator::validateID(id);
    Validator::validateUsername(username);
    validateStoredPassword(password);
    Validator::validateName(first);
    Validator::validateName(last);
    Validator::validateEmail(email);
    Validator::validateCNIC(cnic);
    Validator::validatePhone(phone);
    Validator::validateAddress(address);

    userID_ = id;
    username_ = username;
    password_ = password;
    firstName_ = first;
    lastName_ = last;
    email_ = email;
    cnic_ = cnic;
    phoneNumber_ = phone;
    address_ = address;
    balance_ = balance;
    role_ = "User";
    isActive_ = true;
    createdAt_ = SecurityUtils::getCurrentTimestamp();
}

bool User::login(const string& username, const string& password) const {
    // Check if account is active
    if (!isActive_) {
        return false;
    }
    
    // Check if password is hashed
    if (password_.find(':') != string::npos) {
        // Hashed password format
        string salt = SecurityUtils::extractSalt(password_);
        string storedHash = SecurityUtils::extractHash(password_);
        
        if (username_ == username && 
            SecurityUtils::verifyPassword(password, salt, storedHash)) {
            return true;
        }
    } else {
        // Legacy plaintext password
        if (username_ == username && password_ == password) {
            return true;
        }
    }
    
    return false;
}

bool User::loginWithHash(const string& password) const {
    if (!isActive_) {
        return false;
    }
    
    // For hashed passwords
    if (password_.find(':') != string::npos) {
        string salt = SecurityUtils::extractSalt(password_);
        string storedHash = SecurityUtils::extractHash(password_);
        return SecurityUtils::verifyPassword(password, salt, storedHash);
    }
    
    return false;
}

void User::updateBalance(double amount) {
    // Allow balance to go negative to represent outstanding fines
    // Positive balance = Account credit, Negative balance = Outstanding fines
    balance_ += amount;
}

void User::suspend() {
    isActive_ = false;
}

void User::reinstate() {
    isActive_ = true;
}

bool User::isActive() const {
    return isActive_;
}
 
int User::getUserID() const { return userID_; }
string User::getUsername() const { return username_; }
string User::getRole() const { return role_; }
string User::getFirstName() const { return firstName_; }
string User::getLastName() const { return lastName_; }
string User::getEmail() const { return email_; }
string User::getCNIC() const { return cnic_; }
string User::getPhone() const { return phoneNumber_; }
string User::getAddress() const { return address_; }
double User::getBalance() const { return balance_; }

void User::setEmail(const string& email) { 
    Validator::validateEmail(email);
    email_ = email; 
}

void User::setPhone(const string& phone) { 
    Validator::validatePhone(phone);
    phoneNumber_ = phone; 
}

void User::setAddress(const string& address) { 
    Validator::validateAddress(address);
    address_ = address; 
}

void User::setFirstName(const string& first) { 
    Validator::validateName(first);
    firstName_ = first; 
}

void User::setLastName(const string& last) { 
    Validator::validateName(last);
    lastName_ = last; 
}

bool User::operator==(const User& other) const {
    return userID_ == other.userID_;
}
