#ifndef SYSTEM_EXCEPTIONS_H
#define SYSTEM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class AppException : public std::runtime_error {
public:
    explicit AppException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class ValidationException : public AppException {
public:
    explicit ValidationException(const std::string& msg)
        : AppException("Validation Error: " + msg) {}
};

class OperationCancelledException : public AppException {
public:
    explicit OperationCancelledException(const std::string& msg = "Operation cancelled by user.")
        : AppException(msg) {}
};

class AuthenticationException : public AppException {
public:
    explicit AuthenticationException(const std::string& msg = "Authentication failed: Invalid credentials.")
        : AppException(msg) {}
};

class NotFoundException : public AppException {
public:
    explicit NotFoundException(const std::string& msg)
        : AppException("Not Found: " + msg) {}
};

class AuthorizationException : public AppException {
public:
    explicit AuthorizationException(const std::string& msg)
        : AppException("Authorization Error: " + msg) {}
};

class ResourceStateException : public AppException {
public:
    explicit ResourceStateException(const std::string& msg)
        : AppException("Resource Error: " + msg) {}
};

class BalanceException : public AppException {
public:
    explicit BalanceException(const std::string& msg)
        : AppException("Balance Error: " + msg) {}
};

class InvalidDateException : public AppException {
public:
    explicit InvalidDateException(const std::string& msg)
        : AppException(msg) {}
};

class AlreadyReturnedException : public AppException {
public:
    explicit AlreadyReturnedException(const std::string& msg)
        : AppException(msg) {}
};

class InvalidFineException : public AppException {
public:
    explicit InvalidFineException(const std::string& msg)
        : AppException(msg) {}
};

class EmptyReportException : public AppException {
public:
    explicit EmptyReportException(const std::string& msg)
        : AppException(msg) {}
};

#endif
