#include<iostream>
using namespace std;

class Student{
    string name;
    int rollNo;
    float marks;
    char grade;

    public:
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setrollNO(int rollNO)
    {
        this->rollNo = rollNO;
    }
    int getrollNO()
    {
        return rollNo;
    }
    void setMarks(float marks)
    {
        this->marks = marks;
    }
    float getMarks()
    {
        return marks;
    }
    void setGrade(char grade)
    {
        this->grade = grade;
    }
    char getGrade()
    {
        return grade;
    }

    void calculateGrade(){
        if(marks >= 90 && marks<=100)
        {
            grade ='A';
        }
        else if(marks>=80 && marks<=89)
        {
            grade= 'B';
        }
        else if(marks>=70 && marks<=79)
        {
            grade= 'C';
        }
        else if(marks >60 && marks<=69)
        {
           grade= 'D';
        }
        else{
           grade= 'F';
        }
    }
};

int main()
{
    cout<<"Enter the student info:>>>>>>>>>>>>"<<endl;
    string name;
    cout<<"Enter name:"<<endl;
    cin>>name;
    int rn;
    cout<<"Roll no"<<endl;
    cin>>rn;
    float m;
    cout<<"Marks"<<endl;
    cin>>m;
    char g;
    

    Student s;
    s.setName(name);
    s.setrollNO(rn);
    s.setMarks(m);
    s.setGrade(g);

    s.calculateGrade();

    cout<<"Name :" <<s.getName()<<endl;
    cout<<"Roll no : "<<s.getrollNO()<<endl;
    cout<<"Marks : "<<s.getMarks()<<endl;
    cout<<"Grade : "<<s.getGrade()<<endl; 
}