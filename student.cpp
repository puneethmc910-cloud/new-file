#include<iostream>
#include<string>
using namespace std;

class student
{
    public:
    string name;
    int rollno;
    int marks;
   student(string n,int r,int m)
    {
        name=n;
        rollno=r;
        marks=m;
    }
    void display()
    {
        cout<<"\n student name:"<<name;
        cout<<"\n roll number is :"<<rollno;
        if(marks >= 90)
        {
            cout<<"\n grade:A";
        }
        else if(marks>=75 && marks<=89)
        {
            cout<<"\n grade:B";

        }
         else if(marks>=50 && marks<=74)
        {
            cout<<"\n grade:c";
        }
         else if(marks<=50)
        {
            cout<<"\n grade:F";
        }
    }
};

int main()
{
    student s1("puneeth",101,97);
    student s2("rahul",104,85);
    student s3("shabbir",405,56);
    
    s1.display();
    s2.display();
    s3.display();
    return 0;
}