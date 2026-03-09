#include<iostream>
using namespace std;

class Student{
    int rollNo;
    string name;
    double marks;

    public:
    Student()
    {
        rollNo = 0;
        name="";
        marks = 0.0;
    }
    // Student(int rn , string nm , double m)
    // {
    //     rollNo = rn;
    //     name = nm;
    //     marks = m;
    // }
    Student(int rollNO , string name , double marks)
    {
        this->rollNo = rollNO;
        this->name = name;
        this->marks = marks;
    }
    void displayDetails()
    {
        cout<<"rollNo : "<<rollNo<<endl;
        cout<<"Name :" <<name<<endl;
        cout<<"Marks : "<<marks<<endl;
    }
};
int main()
{
    Student s1;
    Student s2(20,"om",44);
    Student s3(34 , "omkar ",80);

    s1.displayDetails();
    s2.displayDetails();
    s3.displayDetails();
}