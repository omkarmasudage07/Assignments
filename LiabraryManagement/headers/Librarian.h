#pragma once
#include "Person.h"

namespace LibrarySystem {

    class Librarian : public Person {
    private:
        int employeeId;
        double salary;

    public:
        Librarian();
        Librarian(int id, const std::string& name, const std::string& phone,
                  int empId, double salary);

        void displayInfo() const override;

        int getEmployeeId() const { return employeeId; }
        double getSalary() const { return salary; }
        void setSalary(double s) { salary = s; }

        // Special librarian permissions (demonstrated in Library)
        void addBookPermission() const;
        void removeBookPermission() const;
    };

} // namespace LibrarySystem
