#pragma once
#include <string>
#include <iostream>

namespace LibrarySystem {

    enum class BookStatus {
        AVAILABLE,
        ISSUED,
        LOST,
        DAMAGED
    };

    enum class BookGenre {
        FICTION,
        NON_FICTION,
        SCIENCE,
        TECHNOLOGY,
        HISTORY,
        BIOGRAPHY,
        OTHER
    };

    class Book {
    private:
        int bookId;
        std::string title;
        std::string author;
        std::string isbn;
        BookStatus status;
        BookGenre genre;
        int quantity;
        int availableCopies;

    public:
        // Constructors
        Book();
        Book(int id, const std::string& title, const std::string& author,
             const std::string& isbn, int qty = 1, BookGenre genre = BookGenre::OTHER);

        // Getters (const)
        int getBookId() const { return bookId; }
        int getId() const { return bookId; }  // alias for Container::find(int)
        std::string getTitle() const { return title; }
        std::string getName() const { return title; }  // alias for Container::find(string)
        std::string getAuthor() const { return author; }
        std::string getIsbn() const { return isbn; }
        BookStatus getStatus() const { return status; }
        BookGenre getGenre() const { return genre; }
        int getQuantity() const { return quantity; }
        int getAvailableCopies() const { return availableCopies; }

        // Setters
        void setStatus(BookStatus s) { status = s; }
        void setAvailableCopies(int n) { availableCopies = n; }

        // Static helpers
        static std::string statusToString(BookStatus s);
        static std::string genreToString(BookGenre g);
        static BookStatus stringToStatus(const std::string& s);
        static BookGenre stringToGenre(const std::string& g);

        void display() const;

        // Operator Overloading
        Book& operator++();            // pre-increment (increase available)
        Book operator++(int);          // post-increment
        Book& operator--();            // pre-decrement (decrease available)
        Book operator--(int);          // post-decrement
        bool operator==(const Book& other) const;
        bool operator<(const Book& other) const;
        std::string operator[](int index) const; // 0=id,1=title,2=author,3=isbn,4=status

        friend std::ostream& operator<<(std::ostream& os, const Book& b);
        friend std::istream& operator>>(std::istream& is, Book& b);
    };

} // namespace LibrarySystem
