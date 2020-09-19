/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#ifndef EX4_COURSE_H
#define EX4_COURSE_H
#include <string>
using namespace std;
#include "Student.h"
class Student;


class Course{
private:

    string name;
    int number;

    //array to courses;
    Student** ArrayStudentPtr;

    //array to grades:
    int** Grades;

    int studentCounter;

    friend class Student;

public:

    //Constructor:
    Course();

    //Destructor:
    ~Course();

    //Set:
    void setnumber(int num);
    void setname(string name);

    //Get:
    string getname();
    int getnumber();
    Student ** getstudents();
    int ** getgrades();
    int getstudentcounter();

    // = oparator- copy course to another course type:
    void operator = (Course* Course2);

    // == oparator- true/false same number:
    bool operator == (Course* Course2);

    // > oparator- true/false between student number:
    bool operator > (Course* Course2);

    // << oparator- print course:
    friend ostream & operator << (ostream &out, Course* Courseoutput);

    // >> oparator- input course:
    friend istream & operator >> (istream &in, Course* Courseinput);

    // += oparator- add student to course:
    void operator += (Student *Student);

    // -= oparator- remove student from course:
    void operator -= (Student *Student);

    // [] oparator- return student place by index:
    Student* operator [] (int index);
};


#endif //EX4_COURSE_H
