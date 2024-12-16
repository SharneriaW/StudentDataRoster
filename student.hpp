//
//  student.hpp
//  StudentData
//
//  Created by Sharneria Wright on 9/23/24.
//

#pragma once
#include<iostream>
#include<iomanip>
#include "degree.h"
using namespace std;
//using std::endl;

class Student{
public:
    //constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], enum DegreeProgram degreeprogram);
    
    //getters(accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    enum DegreeProgram getDegreeProgram();
    
    //setters(mutators)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(enum DegreeProgram Dp);
    
    //displays the student data
    void print();
    
    
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3]; //Array to store days in the 3 courses
    DegreeProgram degreeProgram;
    
    

};

