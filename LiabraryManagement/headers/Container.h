#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

namespace LibrarySystem {

    template <typename T>
    class Container {
    private:
        T* data;
        int size;
        int capacity;

        void resize() {
            capacity *= 2;
            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

    public:
        // Constructor
        Container(int initialCapacity = 10)
            : size(0), capacity(initialCapacity) {
            data = new T[capacity];
        }

        // Copy Constructor (deep copy)
        Container(const Container& other)
            : size(other.size), capacity(other.capacity) {
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }

        // Assignment Operator
        Container& operator=(const Container& other) {
            if (this != &other) {
                delete[] data;
                size = other.size;
                capacity = other.capacity;
                data = new T[capacity];
                for (int i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        // Destructor
        ~Container() {
            delete[] data;
        }

        // Add element
        void add(const T& item) {
            if (size >= capacity) resize();
            data[size++] = item;
        }

        // Remove by index
        bool removeAt(int index) {
            if (index < 0 || index >= size) return false;
            for (int i = index; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
            return true;
        }

        // Get element by index
        T& get(int index) {
            if (index < 0 || index >= size)
                throw std::out_of_range("Index out of range");
            return data[index];
        }

        const T& get(int index) const {
            if (index < 0 || index >= size)
                throw std::out_of_range("Index out of range");
            return data[index];
        }

        int getSize() const { return size; }
        bool isEmpty() const { return size == 0; }

        // Function Overloading: find by ID
        int find(int id) const {
            for (int i = 0; i < size; i++) {
                if (data[i].getId() == id) return i;
            }
            return -1;
        }

        // Function Overloading: find by name (string)
        int find(const std::string& name) const {
            for (int i = 0; i < size; i++) {
                std::string itemName = data[i].getName();
                // Case-insensitive partial match
                std::string lName = name, lItem = itemName;
                for (char& c : lName) c = tolower(c);
                for (char& c : lItem) c = tolower(c);
                if (lItem.find(lName) != std::string::npos) return i;
            }
            return -1;
        }

        // Display all
        void displayAll() const {
            if (size == 0) {
                std::cout << "  (No records found)\n";
                return;
            }
            for (int i = 0; i < size; i++) {
                data[i].display();
                std::cout << std::string(50, '-') << "\n";
            }
        }
    };

} // namespace LibrarySystem
