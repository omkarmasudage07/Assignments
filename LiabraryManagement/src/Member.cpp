#include "../headers/Member.h"
#include <iostream>
#include <sstream>

namespace LibrarySystem {

    Member::Member()
        : Person(), issuedCount(0), capacity(MAX_BOOKS) {
        issuedBookIds = new int[capacity];
    }

    Member::Member(int id, const std::string& name, const std::string& phone)
        : Person(id, name, phone), issuedCount(0), capacity(MAX_BOOKS) {
        issuedBookIds = new int[capacity];
    }

    // Deep copy constructor
    Member::Member(const Member& other)
        : Person(other.id, other.name, other.phone),
          issuedCount(other.issuedCount), capacity(other.capacity) {
        issuedBookIds = new int[capacity];
        for (int i = 0; i < issuedCount; i++) {
            issuedBookIds[i] = other.issuedBookIds[i];
        }
    }

    Member::~Member() {
        delete[] issuedBookIds;
    }

    void Member::displayInfo() const {
        std::cout << "  [MEMBER]\n"
                  << "  ID       : " << id << "\n"
                  << "  Name     : " << name << "\n"
                  << "  Phone    : " << phone << "\n"
                  << "  Books    : " << issuedCount << "/" << MAX_BOOKS << "\n";
        if (issuedCount > 0) {
            std::cout << "  Issued IDs: ";
            for (int i = 0; i < issuedCount; i++)
                std::cout << issuedBookIds[i] << " ";
            std::cout << "\n";
        }
    }

    // Alias so Container's find(name) can call getName()
    // (inherited from Person — already available)

    bool Member::issueBook(int bookId) {
        if (issuedCount >= MAX_BOOKS) return false;
        issuedBookIds[issuedCount++] = bookId;
        return true;
    }

    bool Member::returnBook(int bookId) {
        for (int i = 0; i < issuedCount; i++) {
            if (issuedBookIds[i] == bookId) {
                for (int j = i; j < issuedCount - 1; j++)
                    issuedBookIds[j] = issuedBookIds[j + 1];
                issuedCount--;
                return true;
            }
        }
        return false;
    }

    bool Member::hasBook(int bookId) const {
        for (int i = 0; i < issuedCount; i++)
            if (issuedBookIds[i] == bookId) return true;
        return false;
    }

    // Deep copy assignment
    Member& Member::operator=(const Member& other) {
        if (this != &other) {
            delete[] issuedBookIds;
            id           = other.id;
            name         = other.name;
            phone        = other.phone;
            issuedCount  = other.issuedCount;
            capacity     = other.capacity;
            issuedBookIds = new int[capacity];
            for (int i = 0; i < issuedCount; i++)
                issuedBookIds[i] = other.issuedBookIds[i];
        }
        return *this;
    }

    bool Member::operator==(const Member& other) const {
        return id == other.id;
    }

    std::ostream& operator<<(std::ostream& os, const Member& m) {
        os << m.id << "|" << m.name << "|" << m.phone << "|" << m.issuedCount;
        for (int i = 0; i < m.issuedCount; i++)
            os << "|" << m.issuedBookIds[i];
        return os;
    }

    std::istream& operator>>(std::istream& is, Member& m) {
        std::string line;
        if (std::getline(is, line)) {
            std::stringstream ss(line);
            std::string token;
            std::getline(ss, token, '|'); m.id = std::stoi(token);
            std::getline(ss, m.name, '|');
            std::getline(ss, m.phone, '|');
            std::getline(ss, token, '|'); m.issuedCount = std::stoi(token);
            for (int i = 0; i < m.issuedCount; i++) {
                std::getline(ss, token, '|');
                m.issuedBookIds[i] = std::stoi(token);
            }
        }
        return is;
    }

} // namespace LibrarySystem
