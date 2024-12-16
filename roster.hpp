//
//  roster.hpp
//  StudentData
//
//  Created by Sharneria Wright on 9/23/24.
//
#pragma once
#include "student.hpp"
class Roster
{
private:
    int lastIndex;
    int numStudents = 5;
    
public:
    Roster();
    Student*classRosterArray[5];
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeprogram);
    void parseAndAdd(string studentData);
    int getLastIndex();
    ~Roster();
};
