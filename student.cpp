//
//  student.cpp
//  StudentData
//
//  Created by Sharneria Wright on 9/23/24.
//
#include "student.hpp"
#include <iostream>

//Constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], enum DegreeProgram degreeProgram)
{
    this->studentID = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++)
    {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

//Getters
string Student::getStudentID()
{
    return this->studentID;
}
string Student::getFirstName()
{
    return this->firstName;
}
string Student::getLastName()
{
    return this->lastName;
}
string Student::getEmailAddress()
{
    return this->emailAddress;
}
int Student::getAge()
{
    return this->age;
}
int* Student::getDaysInCourse() {
    return this->daysInCourse;
}
DegreeProgram Student::getDegreeProgram() {
    return  this->degreeProgram;
}

//Setters
void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}
void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}
void Student::setAge(int age)
{this->age = age;
}
void Student::setDaysInCourse(int daysInCourse[])
{
    for(int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(enum DegreeProgram dp)
{
    this-> degreeProgram = dp;
}

//print method
void Student::print()
{
    cout << this->studentID<< "\t";
    cout << "First Name: " <<this->firstName<< "\t";
    cout << "Last Name: " <<this->lastName<< "\t";
    cout << "Age: " << this->age<< "\t";
    cout << "Days in Course: " << "{" <<this->daysInCourse[0]<< ", ";
    cout << this->daysInCourse[1]<< ", ";
    cout << this->daysInCourse[2] << "}" << "\t";
    if (this->degreeProgram == SECURITY) {
            cout << "SECURITY";
        } else if (this->degreeProgram == NETWORK) {
            cout << "NETWORK";
        } else if (this->degreeProgram == SOFTWARE) {
            cout << "SOFTWARE";
        } else {
            cout << "UNKNOWN";
        }

        cout << '\n'; // this moves to the next line
    }
