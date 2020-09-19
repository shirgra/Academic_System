/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#ifndef EX4_STUDENT_H
#define EX4_STUDENT_H
#include <string>
using namespace std;
#include "Course.h"
class Course;


class Student{
private:

    string name;
    int id;

    char gender;
    //array to courses;
    Course** ArrayCoursePtr;

    int courseCounter;

    friend class Course;


public:

    //Constructor:
    Student();

    //Destructor:
    ~Student();

    //Set:
    void setid(int id);
    void setname(string name);
    void setgender(char gender);

    //Get:
    string getname();
    int getid();
    char getgender();
    Course ** getcourses();
    int getcoursecounter();


    // = oparator- copy student to another student type:
    void operator = (Student* Student2);

    // == oparator- true/false same id:
    bool operator == (Student* Student2);

    // > oparator- true/false between grades average:
    bool operator > (Student* Student2);

    //<< oparator- print student:
    friend ostream & operator << (ostream &out, Student* Studentoutput);

    //>> oparator- input student:
    friend istream & operator >> (istream &in, Student* Studentinput);

    // += oparator- add course to student list:
    void operator += (Course *Course);

    // -= oparator- remove course to student list:
    void operator -= (Course* Course);

    // [] oparator- return course place in student list by index:
    Course* operator [] (int index);
};


#endif //EX4_STUDENT_H
