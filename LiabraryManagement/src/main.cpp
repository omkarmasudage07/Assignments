#include "../headers/Library.h"
#include "../headers/Librarian.h"
#include "../headers/Exceptions.h"
#include <iostream>
#include <limits>
#include <string>

using namespace LibrarySystem;

// ─── Helper ──────────────────────────────────────────────────────────────────
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printHeader(const std::string& title) {
    std::cout << "\n" << std::string(54, '=') << "\n";
    std::cout << "    " << title << "\n";
    std::cout << std::string(54, '=') << "\n";
}

void printMenu() {
    printHeader("LIBRARY MANAGEMENT SYSTEM");
    std::cout << "  [Book Management]\n"
              << "   1. Add New Book\n"
              << "   2. Remove Book\n"
              << "   3. Search Book\n"
              << "   4. Display All Books\n\n"
              << "  [Member Management]\n"
              << "   5. Register Member\n"
              << "   6. Remove Member\n"
              << "   7. Search Member\n"
              << "   8. Display All Members\n\n"
              << "  [Transactions]\n"
              << "   9. Issue Book\n"
              << "  10. Return Book\n"
              << "  11. View Overdue Books\n"
              << "  12. View All Transactions\n\n"
              << "  [Data]\n"
              << "  13. Save Data\n"
              << "  14. Load Data\n\n"
              << "  [Demo]\n"
              << "  15. Polymorphism Demo\n\n"
              << "   0. Exit\n"
              << std::string(54, '-') << "\n"
              << "  Choice: ";
}

// ─── Action Handlers ─────────────────────────────────────────────────────────

void addBook(Library& lib) {
    printHeader("ADD NEW BOOK");
    int id, qty;
    std::string title, author, isbn;
    int genreChoice;

    std::cout << "  Book ID     : "; std::cin >> id; clearInput();
    std::cout << "  Title       : "; std::getline(std::cin, title);
    std::cout << "  Author      : "; std::getline(std::cin, author);
    std::cout << "  ISBN        : "; std::getline(std::cin, isbn);
    std::cout << "  Quantity    : "; std::cin >> qty; clearInput();
    std::cout << "  Genre (0=Fiction, 1=Non-Fiction, 2=Science, 3=Technology, 4=History, 5=Biography, 6=Other): ";
    std::cin >> genreChoice; clearInput();

    BookGenre g = static_cast<BookGenre>(genreChoice % 7);
    Book book(id, title, author, isbn, qty, g);
    lib.addBook(book);
}

void removeBook(Library& lib) {
    printHeader("REMOVE BOOK");
    int id;
    std::cout << "  Enter Book ID: "; std::cin >> id; clearInput();
    lib.removeBook(id);
}

void searchBook(Library& lib) {
    printHeader("SEARCH BOOK");
    std::string query;
    std::cout << "  Enter title, author, or ID: "; std::getline(std::cin, query);
    lib.searchBook(query);
}

void registerMember(Library& lib) {
    printHeader("REGISTER MEMBER");
    int id;
    std::string name, phone;
    std::cout << "  Member ID : "; std::cin >> id; clearInput();
    std::cout << "  Name      : "; std::getline(std::cin, name);
    std::cout << "  Phone     : "; std::getline(std::cin, phone);
    Member m(id, name, phone);
    lib.registerMember(m);
}

void removeMember(Library& lib) {
    printHeader("REMOVE MEMBER");
    int id;
    std::cout << "  Enter Member ID: "; std::cin >> id; clearInput();
    lib.removeMember(id);
}

void searchMember(Library& lib) {
    printHeader("SEARCH MEMBER");
    std::string query;
    std::cout << "  Enter name or ID: "; std::getline(std::cin, query);
    lib.searchMember(query);
}

void issueBook(Library& lib) {
    printHeader("ISSUE BOOK");
    int bookId, memberId;
    std::cout << "  Book ID   : "; std::cin >> bookId;   clearInput();
    std::cout << "  Member ID : "; std::cin >> memberId; clearInput();
    lib.issueBook(bookId, memberId);
}

void returnBook(Library& lib) {
    printHeader("RETURN BOOK");
    int bookId, memberId;
    std::cout << "  Book ID   : "; std::cin >> bookId;   clearInput();
    std::cout << "  Member ID : "; std::cin >> memberId; clearInput();
    lib.returnBook(bookId, memberId);
}

void polymorphismDemo() {
    printHeader("RUNTIME POLYMORPHISM DEMO");
    std::cout << "  Creating Person* pointers to derived objects...\n\n";

    // Upcasting: derived -> base pointer
    Person* p1 = new Member(99, "Alice Student", "555-0001");
    Person* p2 = new Librarian(88, "Bob Librarian", "555-0002", 1001, 45000.0);

    std::cout << "  p1->displayInfo() [Person* -> Member]:\n";
    p1->displayInfo();   // calls Member's version — runtime polymorphism!

    std::cout << "\n  p2->displayInfo() [Person* -> Librarian]:\n";
    p2->displayInfo();   // calls Librarian's version

    // Book [] operator demo
    Book demoBook(1, "The C++ Programming Language", "Bjarne Stroustrup", "978-0321958327", 5);
    std::cout << "\n  Book [] operator demo:\n";
    std::cout << "  book[0]=" << demoBook[0] << "  book[1]=" << demoBook[1]
              << "  book[2]=" << demoBook[2] << "\n";

    // ++ / -- operator demo
    std::cout << "\n  book-- (issue a copy): available=" << demoBook.getAvailableCopies() << " -> ";
    demoBook--;
    std::cout << demoBook.getAvailableCopies() << "\n";
    std::cout << "  book++ (return a copy): available=" << demoBook.getAvailableCopies() << " -> ";
    demoBook++;
    std::cout << demoBook.getAvailableCopies() << "\n";

    delete p1;
    delete p2;
    std::cout << "\n  [Virtual destructor ensures no memory leaks!]\n";
}

// ─── Main ─────────────────────────────────────────────────────────────────────

int main() {
    Library lib;
    int choice;

    std::cout << "\n  Welcome to the Library Management System!\n";
    std::cout << "  Tip: Use option 14 to load saved data, or start fresh.\n";

    do {
        printMenu();
        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "  [ERROR] Invalid input.\n";
            continue;
        }
        clearInput();

        try {
            switch (choice) {
                case 1:  addBook(lib);                    break;
                case 2:  removeBook(lib);                 break;
                case 3:  searchBook(lib);                 break;
                case 4:  lib.displayAllBooks();           break;
                case 5:  registerMember(lib);             break;
                case 6:  removeMember(lib);               break;
                case 7:  searchMember(lib);               break;
                case 8:  lib.displayAllMembers();         break;
                case 9:  issueBook(lib);                  break;
                case 10: returnBook(lib);                 break;
                case 11: lib.displayOverdueBooks();       break;
                case 12: lib.displayAllTransactions();    break;
                case 13: lib.saveData();                  break;
                case 14: lib.loadData();                  break;
                case 15: polymorphismDemo();              break;
                case 0:
                    std::cout << "\n  Goodbye! Happy Reading!\n\n";
                    break;
                default:
                    std::cout << "  [ERROR] Invalid option. Please enter 0-15.\n";
            }
        }
        catch (const BookNotFoundException& e) {
            std::cout << "  [NOT FOUND] " << e.what() << "\n";
        }
        catch (const MemberNotFoundException& e) {
            std::cout << "  [NOT FOUND] " << e.what() << "\n";
        }
        catch (const BookNotAvailableException& e) {
            std::cout << "  [UNAVAILABLE] " << e.what() << "\n";
        }
        catch (const MaxBooksExceededException& e) {
            std::cout << "  [LIMIT REACHED] " << e.what() << "\n";
        }
        catch (const LibraryException& e) {
            std::cout << "  [LIBRARY ERROR] " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "  [ERROR] " << e.what() << "\n";
        }

    } while (choice != 0);

    return 0;
}
