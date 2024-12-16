//
//  roster.cpp
//  StudentData
//
//  Created by Sharneria Wright on 9/23/24.
//

#include "roster.hpp"
#include <iostream>
using namespace std;

//Constructor
Roster::Roster() : numStudents(0), lastIndex(-1) {
    for (int i = 0; i < 5; ++i) { // Initialize array to nullptr
        classRosterArray[i] = nullptr;
    }
}

void Roster::parseAndAdd(string data)
{
    
    size_t rhs = data.find(",");
    string studentID = data.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string firstName = data.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string lastName = data.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string emailAddress = data.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int age = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    string degree = data.substr(lhs);
    DegreeProgram degreeprogram;
    
    if(degree == "SECURITY")
    {
        degreeprogram = SECURITY;
    }
    else if(degree == "NETWORK")
    {
        degreeprogram = NETWORK;
    }
    else
    {
        degreeprogram = SOFTWARE;
    }
    
    //adding the new student to the roster
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
    }


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    //This is to ensure we dont go above the roster capacity
    if(lastIndex<4){
        int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3 };
        classRosterArray[++lastIndex] = new Student (studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
    }
    else{
        cout << "Error: Roster is full" << endl;
    }
}

//removes students from the roster by the student ID.
void Roster::remove(string studentID)
{
    bool success = false;
    for(int i = 0; i<= lastIndex; i++)
    {
        if(classRosterArray[i]->getStudentID() == studentID)
        {
            success = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--;
            break;//loop will break after finding the student
        }
    }
            if(!success)
            {
                cout << "The student with the ID: " << studentID << " was not found."<< endl;
            }
       
}

//prints all the students in the roster
void Roster::printAll()
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if(classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
        
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for(int i = 0; i <= lastIndex; i++)
    {
        if(classRosterArray[i]->getStudentID()==studentID){
            int* days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            cout<< "StudentID: " << studentID << ", average days in course is: " << average << endl;
      }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    for(int i = 0; i <= lastIndex; i++)
    {
        if(Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)classRosterArray[i]->print();
    }
    cout<< endl;
}

void Roster::printInvalidEmails()
{
    for(int i = 0; i <= lastIndex; i++)
    {
        string emailAddress = classRosterArray[i]->getEmailAddress();
        if (emailAddress.find(' ') != string::npos){
            cout << emailAddress << " - no spaces allowed" << endl;
        }
        else if(emailAddress.find('.') == string::npos)
        {
            cout << emailAddress << " - missing period" << endl;
        }
        else if(emailAddress.find('@') == string::npos)
        {
            cout << emailAddress << " - missing symbol"<< endl;
        }
    }
}

int Roster::getLastIndex() {
    return lastIndex;
}
//destuctor
Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        delete classRosterArray[i];
    }
}
