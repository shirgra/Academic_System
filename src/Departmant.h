/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#ifndef EX4_DEPARTMANT_H
#define EX4_DEPARTMANT_H
#include <string>
using namespace std;
#include "Student.h"
#include "Course.h"

class Department{
private:
    string name;
    string depcode;

    Course **DepCourses; //All courses in dep.
    int DepCoursescounter=0;

    Student **DepStudents; //All students in dep.
    int DepStudentsCounter=0;

    Student **DamegedStudents; //Academic situation not valid;
    int DamegedCounter=0;

public:
    //Constructor:
    Department();

    //Destructor:
    ~Department();

    //set:
    void setname(string name);
    void setdepcode(string depcode);

    //get:
    string getname();
    string getcode();
    Course** getDepCourses();
    int getDepCoursescounter();
    Student ** getDepStudents();
    int getDepStudentsCounter();
    Student ** getDamegedStudents();
    int getDamegedCounter();

    // = oparator- copy dep to another dep type:
    void operator = (Department* Dep2);


    // > oparator- true/false between good students:
    bool operator > (Department* Dep2);

    //<< oparator- print Dep.:
    friend ostream & operator << (ostream &out, Department* Dep);

    //>> oparator- input student:
    friend istream & operator >> (istream &in, Department* Dep);

    // += oparator- add course to student list:
    void operator += (Course* course);
    void operator += (Student* student);


};

#endif //EX4_DEPARTMANT_H
