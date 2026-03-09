#include "../headers/Book.h"
#include <iomanip>
#include <sstream>

namespace LibrarySystem {

    Book::Book() : bookId(0), title(""), author(""), isbn(""),
                   status(BookStatus::AVAILABLE), genre(BookGenre::OTHER),
                   quantity(0), availableCopies(0) {}

    Book::Book(int id, const std::string& t, const std::string& a,
               const std::string& i, int qty, BookGenre g)
        : bookId(id), title(t), author(a), isbn(i),
          status(BookStatus::AVAILABLE), genre(g),
          quantity(qty), availableCopies(qty) {}

    std::string Book::statusToString(BookStatus s) {
        switch (s) {
            case BookStatus::AVAILABLE: return "AVAILABLE";
            case BookStatus::ISSUED:    return "ISSUED";
            case BookStatus::LOST:      return "LOST";
            case BookStatus::DAMAGED:   return "DAMAGED";
            default:                    return "UNKNOWN";
        }
    }

    std::string Book::genreToString(BookGenre g) {
        switch (g) {
            case BookGenre::FICTION:     return "FICTION";
            case BookGenre::NON_FICTION: return "NON_FICTION";
            case BookGenre::SCIENCE:     return "SCIENCE";
            case BookGenre::TECHNOLOGY:  return "TECHNOLOGY";
            case BookGenre::HISTORY:     return "HISTORY";
            case BookGenre::BIOGRAPHY:   return "BIOGRAPHY";
            default:                     return "OTHER";
        }
    }

    BookStatus Book::stringToStatus(const std::string& s) {
        if (s == "AVAILABLE") return BookStatus::AVAILABLE;
        if (s == "ISSUED")    return BookStatus::ISSUED;
        if (s == "LOST")      return BookStatus::LOST;
        if (s == "DAMAGED")   return BookStatus::DAMAGED;
        return BookStatus::AVAILABLE;
    }

    BookGenre Book::stringToGenre(const std::string& g) {
        if (g == "FICTION")     return BookGenre::FICTION;
        if (g == "NON_FICTION") return BookGenre::NON_FICTION;
        if (g == "SCIENCE")     return BookGenre::SCIENCE;
        if (g == "TECHNOLOGY")  return BookGenre::TECHNOLOGY;
        if (g == "HISTORY")     return BookGenre::HISTORY;
        if (g == "BIOGRAPHY")   return BookGenre::BIOGRAPHY;
        return BookGenre::OTHER;
    }

    void Book::display() const {
        std::cout << "  Book ID    : " << bookId << "\n"
                  << "  Title      : " << title << "\n"
                  << "  Author     : " << author << "\n"
                  << "  ISBN       : " << isbn << "\n"
                  << "  Genre      : " << genreToString(genre) << "\n"
                  << "  Status     : " << statusToString(status) << "\n"
                  << "  Total Qty  : " << quantity << "\n"
                  << "  Available  : " << availableCopies << "\n";
    }

    // Pre-increment: increase available copies
    Book& Book::operator++() {
        if (availableCopies < quantity) availableCopies++;
        if (availableCopies > 0) status = BookStatus::AVAILABLE;
        return *this;
    }

    // Post-increment
    Book Book::operator++(int) {
        Book temp = *this;
        ++(*this);
        return temp;
    }

    // Pre-decrement: decrease available copies
    Book& Book::operator--() {
        if (availableCopies > 0) {
            availableCopies--;
            if (availableCopies == 0) status = BookStatus::ISSUED;
        }
        return *this;
    }

    // Post-decrement
    Book Book::operator--(int) {
        Book temp = *this;
        --(*this);
        return temp;
    }

    bool Book::operator==(const Book& other) const {
        return bookId == other.bookId;
    }

    bool Book::operator<(const Book& other) const {
        return title < other.title;
    }

    // [] operator: returns different fields by index
    std::string Book::operator[](int index) const {
        switch (index) {
            case 0: return std::to_string(bookId);
            case 1: return title;
            case 2: return author;
            case 3: return isbn;
            case 4: return statusToString(status);
            default: return "Invalid index";
        }
    }

    std::ostream& operator<<(std::ostream& os, const Book& b) {
        os << b.bookId << "|" << b.title << "|" << b.author << "|"
           << b.isbn << "|" << Book::statusToString(b.status) << "|"
           << Book::genreToString(b.genre) << "|"
           << b.quantity << "|" << b.availableCopies;
        return os;
    }

    std::istream& operator>>(std::istream& is, Book& b) {
        std::string line;
        if (std::getline(is, line)) {
            std::stringstream ss(line);
            std::string token;
            std::getline(ss, token, '|'); b.bookId = std::stoi(token);
            std::getline(ss, b.title, '|');
            std::getline(ss, b.author, '|');
            std::getline(ss, b.isbn, '|');
            std::getline(ss, token, '|'); b.status = Book::stringToStatus(token);
            std::getline(ss, token, '|'); b.genre  = Book::stringToGenre(token);
            std::getline(ss, token, '|'); b.quantity = std::stoi(token);
            std::getline(ss, token, '|'); b.availableCopies = std::stoi(token);
        }
        return is;
    }

} // namespace LibrarySystem
