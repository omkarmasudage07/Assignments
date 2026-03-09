#pragma once
#include <exception>
#include <string>

namespace LibrarySystem {

    class LibraryException : public std::exception {
    protected:
        std::string message;
        std::string functionName;
        int lineNumber;
    public:
        LibraryException(const std::string& msg, const std::string& func = "", int line = 0)
            : message(msg), functionName(func), lineNumber(line) {}

        const char* what() const noexcept override {
            return message.c_str();
        }

        std::string getDetails() const {
            return message + " [in " + functionName + " at line " + std::to_string(lineNumber) + "]";
        }
    };

    class BookNotFoundException : public LibraryException {
    public:
        BookNotFoundException(const std::string& func = "", int line = 0)
            : LibraryException("Book not found in the library.", func, line) {}
    };

    class MemberNotFoundException : public LibraryException {
    public:
        MemberNotFoundException(const std::string& func = "", int line = 0)
            : LibraryException("Member not found in the library.", func, line) {}
    };

    class BookNotAvailableException : public LibraryException {
    public:
        BookNotAvailableException(const std::string& func = "", int line = 0)
            : LibraryException("Book is not available for issue.", func, line) {}
    };

    class MaxBooksExceededException : public LibraryException {
    public:
        MaxBooksExceededException(const std::string& func = "", int line = 0)
            : LibraryException("Member has reached the maximum book limit (3 books).", func, line) {}
    };

} // namespace LibrarySystem
