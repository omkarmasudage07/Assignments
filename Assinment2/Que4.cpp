#include<iostream>
using namespace std;

class  Employee{
    int empID;
    string empName;
    double empSalary;

    public:
    void setEmpID(int empID)
    {
        this->empID = empID;
    }
    int getEmpID()
    {
        return empID;
    }
    void setEmpName(string empName)
    {
        this->empName = empName;
    }
    string getEmpName()
    {
        return empName;
    }

    void setEmpSalary(double empSalary)
    {
        this->empSalary = empSalary;
    }

    double grossSalary()
    {
        double bonous;
        if(empSalary <= 5000)
        {
            bonous = empSalary * (10.0/100);
        }
        else if(empSalary > 5000 && empSalary<=10000)
        {
            bonous = empSalary * (15.0/100);
        }
        else{
            bonous = empSalary * (20.0/100);
        }

        return empSalary + bonous;
    }

    void displayEmployeeDetails()
    {
        cout<<"Employee ID: "<<empID<<endl;
        cout<<"Employee Name : "<<empName<<endl;
        cout<<"Employee Salary : "<<empSalary<<endl;
        cout<<"Gross Salary: "<<grossSalary()<<endl;
    }

};

int main()
{
    Employee emp[100];   // array to store employees
    int count = 0;       // number of employees stored
    int choice;

    do {
        cout << "\n===== EMPLOYEE PAYROLL MENU =====\n";
        cout << "1. Add New Employee\n";
        cout << "2. Calculate Gross Salary\n";
        cout << "3. Display Employee Details\n";
        cout << "4. Update Employee Information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: {
                int id;
                string name;
                double salary;
                bool found = false;

                cout << "Enter Employee ID: ";
                cin >> id;

               
                for(int i = 0; i < count; i++)
                {
                    if(emp[i].getEmpID() == id)
                    {
                        found = true;
                        break;
                    }
                }

                if(found)
                {
                    cout << "Employee ID already exists!\n";
                }
                else
                {
                    cout << "Enter Name: ";
                    cin >> name;

                    cout << "Enter Salary: ";
                    cin >> salary;

                    emp[count].setEmpID(id);
                    emp[count].setEmpName(name);
                    emp[count].setEmpSalary(salary);

                    count++;
                    cout << "Employee added successfully!\n";
                }
                break;
            }

            case 2: {
                int id;
                cout << "Enter Employee ID: ";
                cin >> id;

                bool found = false;

                for(int i = 0; i < count; i++)
                {
                    if(emp[i].getEmpID() == id)
                    {
                        cout << "Gross Salary: "
                             << emp[i].grossSalary() << endl;
                        found = true;
                        break;
                    }
                }

                if(!found)
                    cout << "Employee not found!\n";

                break;
            }

            case 3: {
                int id;
                cout << "Enter Employee ID: ";
                cin >> id;

                bool found = false;

                for(int i = 0; i < count; i++)
                {
                    if(emp[i].getEmpID() == id)
                    {
                        emp[i].displayEmployeeDetails();
                        found = true;
                        break;
                    }
                }

                if(!found)
                    cout << "Employee not found!\n";

                break;
            }

            case 4: {
                int id;
                cout << "Enter Employee ID: ";
                cin >> id;

                bool found = false;

                for(int i = 0; i < count; i++)
                {
                    if(emp[i].getEmpID() == id)
                    {
                        string newName;
                        double newSalary;

                        cout << "Enter New Name: ";
                        cin >> newName;

                        cout << "Enter New Salary: ";
                        cin >> newSalary;

                        emp[i].setEmpName(newName);
                        emp[i].setEmpSalary(newSalary);

                        cout << "Employee updated successfully!\n";
                        found = true;
                        break;
                    }
                }

                if(!found)
                    cout << "Employee not found!\n";

                break;
            }

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}