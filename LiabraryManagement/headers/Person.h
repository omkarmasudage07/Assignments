#pragma once
#include <string>
#include <iostream>

namespace LibrarySystem {

    class Person {
    protected:
        int id;
        std::string name;
        std::string phone;

    public:
        Person();
        Person(int id, const std::string& name, const std::string& phone);

        // Pure virtual function — makes Person abstract
        virtual void displayInfo() const = 0;

        // Virtual destructor — prevents resource leaks
        virtual ~Person();

        // Getters (const)
        int getId() const { return id; }
        std::string getName() const { return name; }
        std::string getPhone() const { return phone; }

        // Setters
        void setName(const std::string& n) { name = n; }
        void setPhone(const std::string& p) { phone = p; }
    };

} // namespace LibrarySystem
