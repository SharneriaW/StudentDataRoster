//
//  main.cpp
//  StudentData
//
//  Created by Sharneria Wright on 10/16/24.
//

#include "roster.hpp"

using namespace std;

int main(){
    //1. Print course title, programming language, student ID, and name.
    cout << "Course Title: C867 - Scripting and Programming Applications\n";
    cout << "Programming Language: C++\n";
    cout << "Student ID: 011983085\n";
    cout << "Name: Sharneria Wright\n";
    cout << endl;
    
    Roster classRoster;
    
    const string studentData[] =
    
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
     "A5,Sharneria,Wright,swri780@wgu.edu,22,16,20,30,SOFTWARE"
    };
    
    cout<< "Displaying all students:";
    for(int i = 0; i < 5; i++)
    {
        classRoster.parseAndAdd(studentData[i]);
    }
    
    //a.Print all students
    cout << "\nAll Students:\n";
    classRoster.printAll();
    
    //b. Print Invalid emails
    cout << "\nInvalid Emails:\n";
    classRoster.printInvalidEmails();
    
    //c. Displaying avergae days in course
    cout << "\nDisplaying average days in course:\n";
    for (int i = 0; i <= classRoster.getLastIndex(); i++) {
            classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        };
    //d. Print student by degree
    cout << "\nShowing students in degree program: Software\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    
    //e.Removing students with ID "A3"
    cout << "\nRemoving students with A3\n";
    classRoster.remove("A3");
    
    //f.Print students after removal
    cout << "\nStudents after removal:\n";
    classRoster.printAll();
    
    //e. Attempting to remove A3 again
    cout << "\nAttempting to remove A3 again\n";
    classRoster.remove("A3");

        return 0;
    }
