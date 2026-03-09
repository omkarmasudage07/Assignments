#include "../headers/Librarian.h"
#include <iostream>

namespace LibrarySystem {

    Librarian::Librarian()
        : Person(), employeeId(0), salary(0.0) {}

    Librarian::Librarian(int id, const std::string& name, const std::string& phone,
                         int empId, double sal)
        : Person(id, name, phone), employeeId(empId), salary(sal) {}

    void Librarian::displayInfo() const {
        std::cout << "  [LIBRARIAN]\n"
                  << "  ID          : " << id << "\n"
                  << "  Name        : " << name << "\n"
                  << "  Phone       : " << phone << "\n"
                  << "  Employee ID : " << employeeId << "\n"
                  << "  Salary      : $" << salary << "\n";
    }

    void Librarian::addBookPermission() const {
        std::cout << "  [AUTH] Librarian " << name << " has permission to ADD books.\n";
    }

    void Librarian::removeBookPermission() const {
        std::cout << "  [AUTH] Librarian " << name << " has permission to REMOVE books.\n";
    }

} // namespace LibrarySystem
