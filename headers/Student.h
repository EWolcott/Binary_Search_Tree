#ifndef Student_H
#define Student_H

#include <string>
#include <iostream>
#include <typeinfo>
//Studentclass
class Student
{
public:
    int _idnumber;       //track number
    std::string _name;   //track name
    std::string _course; //track course

    //Base empty constructor
    Student();
    //constructor with parameters
    Student(std::string name, std::string course, int number);

    std::string getName();   //return student name
    int getNumber();         //return student number
    void toString();         //display student info
    std::string getcourse(); //display course info
    friend std::ostream &operator<<(std::ostream &out, Student &student);
    void operator=(const Student &);
    friend bool operator<(const Student &, const Student &);
    friend bool operator>(const Student &, const Student &);
    friend bool operator==(const Student &, const Student &);
};

#endif