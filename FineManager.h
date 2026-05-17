#ifndef FINEMANAGER_H
#define FINEMANAGER_H

class FineManager {
private:
    double finePerDay_;

public:
explicit FineManager(double rate); // copy nhi krskte no error

    double calculateFine(int daysLate) const;

    void deductFine(int userID, double amount);
};

#endif