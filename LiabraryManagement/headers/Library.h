#pragma once
#include "Container.h"
#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include "Exceptions.h"
#include <vector>
#include <map>
#include <string>

namespace LibrarySystem {

    class Library {
    private:
        Container<Book> books;
        Container<Member> members;
        std::vector<Transaction> transactions;
        std::map<int, int> issuedMap;  // bookId -> memberId

        // File paths
        const std::string BOOKS_FILE   = "data/books.txt";
        const std::string MEMBERS_FILE = "data/members.txt";
        const std::string TRANS_FILE   = "data/transactions.txt";

    public:
        Library();

        // Book Management
        void addBook(const Book& book);
        void removeBook(int bookId);
        void searchBook(const std::string& query) const;
        void displayAllBooks() const;
        Book& findBook(int bookId);

        // Member Management
        void registerMember(const Member& member);
        void removeMember(int memberId);
        void searchMember(const std::string& query) const;
        void displayAllMembers() const;
        Member& findMember(int memberId);

        // Transactions
        void issueBook(int bookId, int memberId);
        void returnBook(int bookId, int memberId);
        void displayOverdueBooks() const;
        void displayAllTransactions() const;

        // File Handling
        void saveData() const;
        void loadData();

    private:
        void saveBooks() const;
        void saveMembers() const;
        void saveTransactions() const;
        void loadBooks();
        void loadMembers();
        void loadTransactions();
    };

} // namespace LibrarySystem
