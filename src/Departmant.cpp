/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#include <iostream>
#include "Student.h"
#include "Course.h"
#include "Departmant.h"
using namespace std;


Department::Department() {
    this->name;
    this->depcode;

    this->DepCourses= new Course*[0];
    this->DepCoursescounter=0;

    this->DepStudents= new Student*[0];
    this->DepStudentsCounter=0;

    this->DamegedStudents= new Student*[0];
    this->DamegedCounter=0;

}

Department::~Department() {

}

void Department::setname(string name) {
    this->name=name;
}

void Department::setdepcode(string depcode) {
    for(int i=0;i<=depcode.length()-1;++i){
        if((depcode[i]>='0' && depcode[i]<='9') || depcode[i]=='-'){
            continue;
        }
        else{
            cout<<"invalid input!"<<endl;
            return;
        }
    }
    this->depcode=depcode;
}

string Department::getname() {
    return this->name;
}

string Department::getcode() {
    return this->depcode;
}

Course **Department::getDepCourses() {
    return this->DepCourses;
}

Student **Department::getDepStudents() {
    return this->DepStudents;
}

Student **Department::getDamegedStudents() {
    return this->DamegedStudents;
}

int Department::getDepCoursescounter(){
    return this->DepCoursescounter;
}
int Department::getDepStudentsCounter(){
    return this->DepStudentsCounter;
}
int Department::getDamegedCounter(){
    return this->DamegedCounter;
}

void Department::operator=(Department *Dep2) {
    this->name=Dep2->name;
    this->depcode=Dep2->depcode;

    this->DepCourses=Dep2->DepCourses;
    this->DepCoursescounter=Dep2->DepCoursescounter;

    this->DepStudents=Dep2->DepStudents;
    this->DepStudentsCounter=Dep2->DepStudentsCounter;

    this->DamegedStudents=Dep2->DamegedStudents;
    this->DamegedCounter=Dep2->DamegedCounter;
}

bool Department::operator>(Department *Dep2) {
    int goodofthis=this->DepStudentsCounter-this->DamegedCounter;
    int goodofDep2=Dep2->DepStudentsCounter-Dep2->DamegedCounter;
    return (goodofthis>goodofDep2);
}

ostream &operator<<(ostream &out, Department *Dep) {
    cout<<"Printing Department information:"<<endl;
    cout<<"Name: "<<Dep->getname()<<endl;
    cout<<"Code: "<<Dep->getcode()<<endl;

    //Print Courses:
    cout<<"COURSES IN DEPARTMENT:"<<endl;
    if(Dep->DepCoursescounter==0){
        cout<<"No Courses."<<endl;
    }
    else{
        for(int i=0;i<Dep->DepCoursescounter;++i){
            cout<<Dep->DepCourses[i]->getname()<<", ";
            cout<<Dep->DepCourses[i]->getnumber()<<endl;
        }
    }

    //Print Students:
    cout<<"STUDENTS IN DEPARTMENT:"<<endl;
    if(Dep->DepStudentsCounter==0){
        cout<<"No Students."<<endl;
    }
    else{
        for(int i=0;i<Dep->DepStudentsCounter;++i){
            cout<<Dep->DepStudents[i]->getname()<<", ";
            cout<<Dep->DepStudents[i]->getid()<<endl;
        }
    }

    //Print Damaged Students:
    cout<<"STUDENTS IN DEPARTMENT:"<<endl;
    if(Dep->DamegedCounter==0){
        cout<<"No Students."<<endl;
    }
    else{
        for(int i=0;i<Dep->DamegedCounter;++i){
            cout<<Dep->DamegedStudents[i]->getname()<<", ";
            cout<<Dep->DamegedStudents[i]->getid()<<endl;
        }
    }
}

istream &operator>>(istream &in, Department *Dep) {
    string name;
    string code;
    if(Dep== NULL){
        *Dep=Department();
    }

    cout<<"Input Department:"<<endl;

    //Name:
    cout<<"Please enter Name: ";
    cin>>name;
    cout<<endl;
    Dep->name=name;
 //   while(getchar()!='\n'); //Clean the buffer;
    //Code:
    cout<<"Please enter Code: ";
    cin>>code;
    cout<<endl;
    Dep->depcode=code;
//    while(getchar()!='\n'); //Clean the buffer;
}

void Department::operator+=(Course *course) {
    class Course **temparray;
    for(int i=0;i<this->DepCoursescounter;++i){
        if(this->DepCourses[i]==course){
            return;
        }
    }

    if(this->DepCourses[0]== NULL){
        this->DepCourses=new class Course*[1];
        this->DepCourses[0]=course;
    }
    else{
        int size= (sizeof(this->DepCourses)/ sizeof(*this->DepCourses));
        temparray=new class Course*[size+1];
        for(int i=0;i<(size);++i){
            temparray[i]=this->DepCourses[i];
        }

        delete[]this->DepCourses;

        temparray[size]=course;
        this->DepCourses=temparray;
    }
    this->DepCoursescounter++;
}

void Department::operator+=(Student *student) {
    class Student **temparray;
    for(int i=0;i<this->DepStudentsCounter;++i){
        if(this->DepStudents[i]==student){
            return;
        }
    }

    if(this->DepStudents[0]==NULL){
        this->DepStudents=new class Student*[1];
        this->DepStudents[0]=student;
    }
    else{
        int size= (sizeof(this->DepStudents)/ sizeof(*this->DepStudents));
        temparray=new class Student*[size+1];
        for(int i=0;i<size;++i){
            temparray[i]=this->DepStudents[i];
        }
        delete[]this->DepStudents;
        temparray[size]=student;
        this->DepStudents=temparray;
    }
    this->DepStudentsCounter++;
}


