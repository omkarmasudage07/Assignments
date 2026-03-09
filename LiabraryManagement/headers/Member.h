#pragma once
#include "Person.h"
#include <iostream>

namespace LibrarySystem {

    const int MAX_BOOKS = 3;

    class Member : public Person {
    private:
        int issuedCount;
        int* issuedBookIds;   // dynamic array
        int capacity;

    public:
        // Constructors & Destructor
        Member();
        Member(int id, const std::string& name, const std::string& phone);
        Member(const Member& other);   // Copy constructor (deep copy)
        ~Member();                     // Destructor

        // Overrides
        void displayInfo() const override;

        // Book tracking
        bool issueBook(int bookId);
        bool returnBook(int bookId);
        bool hasBook(int bookId) const;
        int getIssuedCount() const { return issuedCount; }
        int* getIssuedBookIds() const { return issuedBookIds; }

        // Operator Overloading
        Member& operator=(const Member& other);
        bool operator==(const Member& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Member& m);
        friend std::istream& operator>>(std::istream& is, Member& m);
    };

} // namespace LibrarySystem
