#include "../headers/Transaction.h"
#include <iomanip>
#include <sstream>
#include <cmath>

namespace LibrarySystem {

    // Static member definitions
    int Transaction::nextTransactionId = 1;
    const double Transaction::FINE_RATE_PER_DAY = 2.0;  // $2 per day

    Transaction::Transaction()
        : transactionId(0), memberId(0), bookId(0),
          issueDate(0), dueDate(0), returnDate(0),
          fineAmount(0.0), returned(false) {}

    Transaction::Transaction(int mId, int bId, int dueDays)
        : transactionId(nextTransactionId++),
          memberId(mId), bookId(bId),
          returnDate(0), fineAmount(0.0), returned(false) {
        issueDate = time(nullptr);
        dueDate   = issueDate + (dueDays * 24 * 3600);
    }

    std::string Transaction::timeToString(time_t t) {
        if (t == 0) return "N/A";
        char buf[20];
        tm* tm_info = localtime(&t);
        strftime(buf, sizeof(buf), "%Y-%m-%d", tm_info);
        return std::string(buf);
    }

    bool Transaction::isOverdue() const {
        if (returned) return false;
        return time(nullptr) > dueDate;
    }

    int Transaction::getDaysOverdue() const {
        if (!isOverdue()) return 0;
        double diff = difftime(time(nullptr), dueDate);
        return (int)(diff / (24 * 3600));
    }

    double Transaction::calculateFine() const {
        int days = getDaysOverdue();
        return days * FINE_RATE_PER_DAY;
    }

    double Transaction::processReturn() {
        returnDate  = time(nullptr);
        returned    = true;
        int overdue = (int)(difftime(returnDate, dueDate) / (24 * 3600));
        fineAmount  = (overdue > 0) ? overdue * FINE_RATE_PER_DAY : 0.0;
        return fineAmount;
    }

    void Transaction::display() const {
        std::cout << "  Transaction ID : " << transactionId << "\n"
                  << "  Member ID      : " << memberId << "\n"
                  << "  Book ID        : " << bookId << "\n"
                  << "  Issue Date     : " << timeToString(issueDate) << "\n"
                  << "  Due Date       : " << timeToString(dueDate) << "\n"
                  << "  Return Date    : " << (returned ? timeToString(returnDate) : "Not returned") << "\n"
                  << "  Fine           : $" << std::fixed << std::setprecision(2) << fineAmount << "\n"
                  << "  Status         : " << (returned ? "RETURNED" : (isOverdue() ? "OVERDUE" : "ACTIVE")) << "\n";
    }

    std::ostream& operator<<(std::ostream& os, const Transaction& t) {
        os << t.transactionId << "|" << t.memberId << "|" << t.bookId << "|"
           << t.issueDate << "|" << t.dueDate << "|" << t.returnDate << "|"
           << t.fineAmount << "|" << t.returned;
        return os;
    }

    std::istream& operator>>(std::istream& is, Transaction& t) {
        std::string line;
        if (std::getline(is, line)) {
            std::stringstream ss(line);
            std::string token;
            std::getline(ss, token, '|'); t.transactionId = std::stoi(token);
            std::getline(ss, token, '|'); t.memberId      = std::stoi(token);
            std::getline(ss, token, '|'); t.bookId        = std::stoi(token);
            std::getline(ss, token, '|'); t.issueDate     = (time_t)std::stoll(token);
            std::getline(ss, token, '|'); t.dueDate       = (time_t)std::stoll(token);
            std::getline(ss, token, '|'); t.returnDate    = (time_t)std::stoll(token);
            std::getline(ss, token, '|'); t.fineAmount    = std::stod(token);
            std::getline(ss, token, '|'); t.returned      = (token == "1");

            // Keep nextTransactionId ahead of loaded IDs
            if (t.transactionId >= Transaction::nextTransactionId)
                Transaction::nextTransactionId = t.transactionId + 1;
        }
        return is;
    }

} // namespace LibrarySystem
