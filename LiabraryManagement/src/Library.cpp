#include "../headers/Library.h"
#include <fstream>
#include <iostream>
#include <iomanip>

namespace LibrarySystem {

    Library::Library() {}

    // ─── Book Management ──────────────────────────────────────────────

    void Library::addBook(const Book& book) {
        books.add(book);
        std::cout << "  [OK] Book added: " << book.getTitle() << "\n";
    }

    void Library::removeBook(int bookId) {
        int idx = books.find(bookId);
        if (idx == -1)
            throw BookNotFoundException(__FUNCTION__, __LINE__);
        books.removeAt(idx);
        std::cout << "  [OK] Book removed.\n";
    }

    Book& Library::findBook(int bookId) {
        int idx = books.find(bookId);
        if (idx == -1)
            throw BookNotFoundException(__FUNCTION__, __LINE__);
        return books.get(idx);
    }

    void Library::searchBook(const std::string& query) const {
        std::cout << "\n  Search results for \"" << query << "\":\n";
        std::cout << std::string(50, '=') << "\n";
        bool found = false;
        for (int i = 0; i < books.getSize(); i++) {
            const Book& b = books.get(i);
            std::string t = b.getTitle(), a = b.getAuthor();
            std::string q = query;
            for (char& c : t) c = tolower(c);
            for (char& c : a) c = tolower(c);
            for (char& c : q) c = tolower(c);
            if (t.find(q) != std::string::npos || a.find(q) != std::string::npos
                || std::to_string(b.getBookId()) == query) {
                b.display();
                std::cout << std::string(50, '-') << "\n";
                found = true;
            }
        }
        if (!found) std::cout << "  No books found.\n";
    }

    void Library::displayAllBooks() const {
        std::cout << "\n  ===== ALL BOOKS =====\n";
        books.displayAll();
    }

    // ─── Member Management ────────────────────────────────────────────

    void Library::registerMember(const Member& member) {
        members.add(member);
        std::cout << "  [OK] Member registered: " << member.getName() << "\n";
    }

    void Library::removeMember(int memberId) {
        int idx = members.find(memberId);
        if (idx == -1)
            throw MemberNotFoundException(__FUNCTION__, __LINE__);
        members.removeAt(idx);
        std::cout << "  [OK] Member removed.\n";
    }

    Member& Library::findMember(int memberId) {
        int idx = members.find(memberId);
        if (idx == -1)
            throw MemberNotFoundException(__FUNCTION__, __LINE__);
        return members.get(idx);
    }

    void Library::searchMember(const std::string& query) const {
        std::cout << "\n  Search results for \"" << query << "\":\n";
        std::cout << std::string(50, '=') << "\n";
        bool found = false;
        for (int i = 0; i < members.getSize(); i++) {
            const Member& m = members.get(i);
            std::string n = m.getName(), q = query;
            for (char& c : n) c = tolower(c);
            for (char& c : q) c = tolower(c);
            if (n.find(q) != std::string::npos || std::to_string(m.getId()) == query) {
                m.displayInfo();
                std::cout << std::string(50, '-') << "\n";
                found = true;
            }
        }
        if (!found) std::cout << "  No members found.\n";
    }

    void Library::displayAllMembers() const {
        std::cout << "\n  ===== ALL MEMBERS =====\n";
        for (int i = 0; i < members.getSize(); i++) {
            members.get(i).displayInfo();
            std::cout << std::string(50, '-') << "\n";
        }
        if (members.getSize() == 0) std::cout << "  (No members registered)\n";
    }

    // ─── Transactions ─────────────────────────────────────────────────

    void Library::issueBook(int bookId, int memberId) {
        Book& book     = findBook(bookId);
        Member& member = findMember(memberId);

        if (book.getAvailableCopies() == 0)
            throw BookNotAvailableException(__FUNCTION__, __LINE__);

        if (member.getIssuedCount() >= MAX_BOOKS)
            throw MaxBooksExceededException(__FUNCTION__, __LINE__);

        --book;   // decrease available copies (operator--)
        member.issueBook(bookId);
        issuedMap[bookId] = memberId;

        Transaction t(memberId, bookId, 14);
        transactions.push_back(t);

        std::cout << "  [OK] Book \"" << book.getTitle()
                  << "\" issued to " << member.getName()
                  << ". Due date: " << Transaction::timeToString(t.getDueDate()) << "\n";
    }

    void Library::returnBook(int bookId, int memberId) {
        Book& book     = findBook(bookId);
        Member& member = findMember(memberId);

        if (!member.hasBook(bookId)) {
            std::cout << "  [ERROR] This member does not have this book.\n";
            return;
        }

        // Find active transaction
        for (auto& t : transactions) {
            if (t.getBookId() == bookId && t.getMemberId() == memberId && !t.isReturned()) {
                double fine = t.processReturn();
                ++book;  // increase available copies (operator++)
                member.returnBook(bookId);
                issuedMap.erase(bookId);

                std::cout << "  [OK] Book returned: \"" << book.getTitle() << "\"\n";
                if (fine > 0)
                    std::cout << "  [FINE] Overdue fine: $" << std::fixed
                              << std::setprecision(2) << fine << "\n";
                else
                    std::cout << "  No fine. Returned on time!\n";
                return;
            }
        }
        std::cout << "  [ERROR] No active transaction found.\n";
    }

    void Library::displayOverdueBooks() const {
        std::cout << "\n  ===== OVERDUE BOOKS =====\n";
        bool found = false;
        for (const auto& t : transactions) {
            if (!t.isReturned() && t.isOverdue()) {
                t.display();
                std::cout << std::string(50, '-') << "\n";
                found = true;
            }
        }
        if (!found) std::cout << "  No overdue books!\n";
    }

    void Library::displayAllTransactions() const {
        std::cout << "\n  ===== ALL TRANSACTIONS =====\n";
        if (transactions.empty()) { std::cout << "  (None)\n"; return; }
        for (const auto& t : transactions) {
            t.display();
            std::cout << std::string(50, '-') << "\n";
        }
    }

    // ─── File Handling ────────────────────────────────────────────────

    void Library::saveData() const {
        saveBooks();
        saveMembers();
        saveTransactions();
        std::cout << "  [OK] All data saved to files.\n";
    }

    void Library::saveBooks() const {
        std::ofstream file(BOOKS_FILE);
        if (!file) { std::cerr << "  [ERROR] Cannot open " << BOOKS_FILE << "\n"; return; }
        for (int i = 0; i < books.getSize(); i++)
            file << books.get(i) << "\n";
    }

    void Library::saveMembers() const {
        std::ofstream file(MEMBERS_FILE);
        if (!file) { std::cerr << "  [ERROR] Cannot open " << MEMBERS_FILE << "\n"; return; }
        for (int i = 0; i < members.getSize(); i++)
            file << members.get(i) << "\n";
    }

    void Library::saveTransactions() const {
        std::ofstream file(TRANS_FILE);
        if (!file) { std::cerr << "  [ERROR] Cannot open " << TRANS_FILE << "\n"; return; }
        for (const auto& t : transactions)
            file << t << "\n";
    }

    void Library::loadData() {
        loadBooks();
        loadMembers();
        loadTransactions();
        std::cout << "  [OK] Data loaded from files.\n";
    }

    void Library::loadBooks() {
        std::ifstream file(BOOKS_FILE);
        if (!file) return;
        Book b;
        while (file >> b) {
            if (b.getBookId() != 0) books.add(b);
        }
    }

    void Library::loadMembers() {
        std::ifstream file(MEMBERS_FILE);
        if (!file) return;
        Member m;
        while (file >> m) {
            if (m.getId() != 0) members.add(m);
        }
    }

    void Library::loadTransactions() {
        std::ifstream file(TRANS_FILE);
        if (!file) return;
        Transaction t;
        while (file >> t) {
            if (t.getTransactionId() != 0) {
                transactions.push_back(t);
                if (!t.isReturned())
                    issuedMap[t.getBookId()] = t.getMemberId();
            }
        }
    }

} // namespace LibrarySystem
