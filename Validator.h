#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <stdexcept>
#include <string>
#include <cctype>
#include <vector>

class Validator {
public:
    // ---------------- MACRO CATEGORIES ----------------
    static std::string getMacroCategory(const std::string& detailedCategory);
    static std::vector<std::string> getMacroCategoryList();
    static bool isValidMacroCategory(const std::string& macroCat);

    // ---------------- INPUT PARSING ----------------
    static int parseInt(const std::string& input);
    static void validateMenuChoice(int choice, int minValue, int maxValue);

// ---------------- BASIC VALIDATION ----------------
    static void validateID(int id);
    static void validatePositiveOrZero(int id);
    static void validateMenuChoiceWithZero(int id);
    static void validateString(const std::string& str);
    static void validateName(const std::string& name);
    static void validateUsername(const std::string& username);
    static void validateAddress(const std::string& address);
    static void validateDate(const std::string& date);
    static void validateCategory(const std::string& category);
    static void validateUrl(const std::string& url);
    static void validateFileFormat(const std::string& format);

    // ---------------- RESOURCE VALIDATION ----------------
    static void validateISBN(const std::string& isbn);
    static void validatePages(int pages);
    static void validateFileSize(float size);

    // ---------------- USER VALIDATION ----------------
    static void validateEmail(const std::string& email);
    static void validateCNIC(const std::string& cnic);
    static void validatePhone(const std::string& phone);
    static void validatePassword(const std::string& password);
};

#endif
