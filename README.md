# 📚 LIBRARY AND RESOURCE MANAGEMENT SYSTEM

### C++ OOP CEP Project | CS-116

---

## Developed By

- **Rumaisa Waseem** (CS-25052)
- **Laiba Qasim** (CS-25069)
- **Aleena Khalid** (CS-25056)

| Academic Information | Details |
|---|---|
| Section | B |
| Semester | Spring 2026 |
| Department | Computer & Information Systems Engineering |
| University | NED University of Engineering & Technology |

---

# 1. PROJECT OVERVIEW

The **Library Management System** is a console-based application developed in C++ using advanced Object-Oriented Programming concepts and modular software design principles.

It simulates a real-world library environment where members can:

- Borrow books
- Return books
- Reserve resources
- Pay fines
- Manage accounts

Administrators can efficiently manage:

- Users
- Resources
- Reports
- Notifications
- Analytics

---

## Core Objectives

- Implement advanced OOP concepts in C++
- Simulate a complete real-world library management environment
- Design a modular and scalable architecture
- Automate traditional library operations
- Store records permanently using file handling
- Generate reports and analytics

---

# 2. SYSTEM INITIALIZATION

On the first run, the system automatically initializes all required files and folders.

## First-Time Setup

1. Register the **Super Admin**
2. Enter the Admin Access Code
3. Login using admin credentials
4. Add members and resources
5. Start using the system

---

## Admin Access Code

```text
LibraryAdmin2026!
```

---

## Demo Credentials

```text
Username : RumaisaWaseem_
Password : Neduet@52
```

---

# 3. SYSTEM FEATURES

## 3.1 USER ACCOUNT MANAGEMENT

- Member and admin registration
- Secure login system
- Password hashing and salting
- Lockout policy
- Membership renewal
- Account suspension and reinstatement

---

## 3.2 RESOURCE MANAGEMENT

- Add/update/remove books and eBooks
- ISBN management
- Category assignment
- Inventory tracking

---

## 3.3 SEARCH & FILTERING

- Search by title
- Search by author
- Search by ISBN
- Search by category
- Partial keyword matching

---

## 3.4 BORROWING & RETURN

- Borrow physical books and eBooks
- Membership-based borrowing limits
- Due-date management
- Automatic fine calculation
- Borrow extension requests
- Borrow history tracking

---

## 3.5 RESERVATION & WAITLIST

- Reserve physical resources
- FIFO waitlist system
- Automatic notifications on availability

---

## 3.6 FINE MANAGEMENT

- Automatic overdue fines
- Fine payment using member balance
- Damage fee support
- Auto suspension for excessive fines

---

## 3.7 NOTIFICATION SYSTEM

- Borrow/return alerts
- Reservation notifications
- Fine alerts
- Extension notifications
- Admin announcements

---

## 3.8 REPORTS & ANALYTICS

- Borrowing reports
- Member activity analytics
- Inventory reports
- Resource popularity analysis

---

## 3.9 BOOK RATINGS & REVIEWS

- 1–5 star ratings
- Written reviews
- One review per member
- Admin moderation

---

## 3.10 SECURITY

- Password hashing with salt
- Secure admin registration code
- Login attempt limitation
- Role-based access control
- Input validation
- Audit logging

---

# 4. ADMIN ROLE HIERARCHY

| Role | Permissions |
|---|---|
| Super Admin | Complete system access |
| Standard Admin | Borrow/return management |
| Librarian | Resource inventory management |
| Notification Admin | Announcement management |
| Fine Manager | Fine handling |

---

# 5. MEMBERSHIP TIERS & FEE STRUCTURE

| Tier | Borrow Limit | Borrow Period | Annual Fee |
|---|---|---|---|
| Silver | 2 Books | 14 Days | Rs. 500 |
| Gold | 5 Books | 21 Days | Rs. 1,000 |
| Platinum | 10 Books | 30 Days | Rs. 2,000 |

---

## Fine Structure

| Type | Details |
|---|---|
| Overdue Fine | Rs. 10/day |
| Damage Fee | Applied by admin |
| Borrow Extension | Up to 14 days |
| Auto Suspension | Fines > Rs. 10,000 |

---

# 6. OOP CONCEPTS IMPLEMENTED

| Concept | Implementation |
|---|---|
| Encapsulation | Private data members with getters/setters |
| Inheritance | User → Member/Admin |
| Polymorphism | Virtual function overriding |
| Abstraction | Abstract Resource class |
| Composition | LibraryManager ownership |
| Exception Handling | Custom exception hierarchy |
| STL Containers | vector, map, set |
| Static Methods | Validation & security helpers |
| Design Patterns | Singleton, Factory, Observer-like |

---

# 7. PROJECT STRUCTURE

```text
LibraryManagementSystem/
│
├── main.cpp
│
├── User.h / User.cpp
├── Member.h / Member.cpp
├── Admin.h / Admin.cpp
├── Resource.h / Resource.cpp
├── Book.h / Book.cpp
├── Ebook.h / Ebook.cpp
├── BorrowRecord.h / BorrowRecord.cpp
├── FineManager.h / FineManager.cpp
├── UserManager.h / UserManager.cpp
├── LibraryManager.h / LibraryManager.cpp
├── Notification.h / Notification.cpp
├── ReportGenerator.h / ReportGenerator.cpp
├── SecurityUtils.h / SecurityUtils.cpp
├── Validator.h / Validator.cpp
├── InputHelper.h / InputHelper.cpp
├── AuditLogger.h / AuditLogger.cpp
├── AdminAnalytics.h / AdminAnalytics.cpp
├── AdvancedSearch.h / AdvancedSearch.cpp
├── BookRating.h / BookRating.cpp
├── BorrowExtension.h / BorrowExtension.cpp
│
└── README.md
```

---

# 8. IMPLEMENTATION STATUS

## Fully Implemented

- User registration and authentication
- Resource management
- Borrow/return processing
- Role-based access control
- Notification system
- Reports and analytics
- Ratings and reviews
- File persistence
- Exception handling

---

## Partially Implemented

- Extension approval workflow improvements
- Enhanced rating analytics
- Memory cleanup edge cases

---

## Not Implemented

- Email notifications
- Database integration
- Multi-threading
- Web interface

---

# 9. FUTURE IMPROVEMENTS

- MySQL database integration
- GUI/web interface
- Cloud storage support
- Email notifications
- Advanced analytics dashboard

---

# 🎓 Academic Project

Developed as a semester project for the CS-116 Object-Oriented Programming course at NED University of Engineering & Technology.
