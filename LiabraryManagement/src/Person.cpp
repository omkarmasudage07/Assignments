#include "../headers/Person.h"

namespace LibrarySystem {

    Person::Person() : id(0), name(""), phone("") {}

    Person::Person(int id, const std::string& name, const std::string& phone)
        : id(id), name(name), phone(phone) {}

    Person::~Person() {
        // Virtual destructor ensures derived destructors are called
    }

} // namespace LibrarySystem
