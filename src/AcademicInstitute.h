/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#ifndef EX4_ACADEMICINSTITUTE_H
#define EX4_ACADEMICINSTITUTE_H
#include <string>
using namespace std;
#include "Student.h"
#include "Course.h"


class AcademicInstitute{
private:
    string name;

    Department ** departments;
    int depcounter=0;
    Student **allstudents;
    int allstucounter=0;
    Student **damagedstudents;
    int damstucounter=0;

public:
    //Constructor:
    AcademicInstitute();

    //Destructor:
    ~AcademicInstitute();

    //set:
    void setname(string name);

    //get:
    string getname();
    Department** getdepartment();
    Student ** getALLstudents();
    Student ** getDAMstudents();

    //MENU:
    void menu();

    //MENU functions:
    void AddDepartment();

    void AddCoursetodepartment();

    void AddStudenttodepartment();

    void RegisterStudentToCourse();

    void GradingStudentsInCourse();

    //help function to grade students:
    void gradingthiscourse(Course* course);

    void PrintCourseInformation();

    void PrintStudentInformation();

    void PrintCDepartmentInformation();

    void RemoveStudentfromCourse();
};

#endif //EX4_ACADEMICINSTITUTE_H
