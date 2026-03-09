#pragma once
#include <string>
#include <ctime>
#include <iostream>

namespace LibrarySystem {

    class Transaction {
    private:
        int transactionId;
        int memberId;
        int bookId;
        time_t issueDate;
        time_t dueDate;
        time_t returnDate;
        double fineAmount;
        bool returned;

        // Static members
        static int nextTransactionId;
        static const double FINE_RATE_PER_DAY;  // fine per day overdue

    public:
        Transaction();
        Transaction(int memberId, int bookId, int dueDays = 14);

        // Getters
        int getTransactionId() const { return transactionId; }
        int getMemberId() const { return memberId; }
        int getBookId() const { return bookId; }
        time_t getIssueDate() const { return issueDate; }
        time_t getDueDate() const { return dueDate; }
        time_t getReturnDate() const { return returnDate; }
        double getFineAmount() const { return fineAmount; }
        bool isReturned() const { return returned; }

        // Operations
        double processReturn();         // sets returnDate, calculates fine
        bool isOverdue() const;
        int getDaysOverdue() const;
        double calculateFine() const;

        void display() const;

        static std::string timeToString(time_t t);
        static double getFineRate() { return FINE_RATE_PER_DAY; }

        // For file I/O
        friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
        friend std::istream& operator>>(std::istream& is, Transaction& t);
    };

} // namespace LibrarySystem
