#include<iostream>
using namespace std;

class Employee{
    const int empID;
    string name;
    double salary;

    public:
    Employee(int empID , string name , double salary):empID(empID) , name(name) , salary(salary)
    { 

    }
    void displayDetails()
    {
        cout<<"rollNo : "<<empID<<endl;
        cout<<"Name :" <<name<<endl;
        cout<<"sal : "<<salary<<endl;
    }
};
int main()
{
    Employee e(12,"omkar",40000);

    e.displayDetails();
    
}