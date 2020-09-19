/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#include <iostream>
#include "Student.h"
#include "Course.h"
using namespace std;

Student::Student() {
    this->name;
    this->gender;
    this->id;
    this->courseCounter=0;
    //link to courses:
    Course *clst[0];
    this->ArrayCoursePtr=clst;
    this->ArrayCoursePtr[0]= nullptr;
}


Student::~Student() {
}

void Student::setid(int id) {
    this->id=id;
}

void Student::setname(string name) {
    this->name=name;
}

void Student::setgender(char gender) {
    this->gender=gender;
}

//Get:
string Student::getname() {
    return this->name;
}
int Student::getid(){
    return this->id;
}
char Student::getgender(){
    return this->gender;
}
Course ** Student::getcourses(){
    return this->ArrayCoursePtr;
}
int Student::getcoursecounter(){
    return this->courseCounter;
}


void Student::operator=(Student *Student2) {
    this->id=Student2->id;
    this->gender=Student2->gender;
    this->name=Student2->name;
    this->courseCounter=Student2->courseCounter;
    this->ArrayCoursePtr=Student2->ArrayCoursePtr;
}


bool Student::operator==(Student *Student2) {
    bool tempbool=false;
    if(this->id==Student2->id){
        tempbool= true;
    }
    return tempbool;
}

bool Student::operator>(Student *Student2) {
    int avrg1=0;
    int avrg2=0;

    //comp avrg1
    for(int i=0; i<this->courseCounter;++i){
        for(int j=0; j<this->ArrayCoursePtr[i]->studentCounter;++j){
            if(this->getid()==this->ArrayCoursePtr[i]->ArrayStudentPtr[j]->getid()){
                avrg1+=*this->ArrayCoursePtr[i]->Grades[j];
            }
        }
    }
    avrg1= avrg1/this->courseCounter;

    //comp avrg1
    for(int i=0; i<Student2->courseCounter;++i){
        for(int j=0; j<Student2->ArrayCoursePtr[i]->studentCounter;++j){
            if(Student2->getid()==(Student2->ArrayCoursePtr[i]->ArrayStudentPtr[j]->getid())){
                avrg2+=*Student2->ArrayCoursePtr[i]->Grades[j];
            }
        }
    }
    avrg2= avrg2/Student2->courseCounter;

    return (avrg1>avrg2);
}

ostream &operator<<(ostream &out, Student *Studentoutput) {
    cout<<"Printing Student:"<<endl;
    cout<<"Name: "<<Studentoutput->name<<endl;
    cout<<"Id: "<<Studentoutput->id<<endl;
    cout<<"Gender: "<<Studentoutput->gender<<endl;
    cout<<"Number of Courses: "<<Studentoutput->courseCounter<<endl;
    if(Studentoutput->courseCounter==0){
        cout<<"No Courses."<<endl;
    }
    else{
        cout<<"Courses:"<<endl;
        for(int i=0;i<Studentoutput->courseCounter;++i){
            cout<<Studentoutput->ArrayCoursePtr[i]->getname()<<", ";
            cout<<Studentoutput->ArrayCoursePtr[i]->getnumber()<<endl;
        }
    }

}

istream &operator>>(istream &in, Student *Studentinput) {
    string name;
    int id;
    char gender;
    if(Studentinput== NULL){
        *Studentinput=Student();
    }

    cout<<"Input Student:"<<endl;

    //Name:
    cout<<"Please enter Name: ";
    cin>>name;
    cout<<endl;
    Studentinput->name=name;
//   while(getchar()!='\n'); //Clean the buffer;
    //Id:
    cout<<"Please enter Id: ";
    cin>>id;
    cout<<endl;
    Studentinput->id=id;
//    while(getchar()!='\n'); //Clean the buffer;
    //Gender:
    cout<<"Please enter Gender (F/M): ";
    cin>>gender;
    cout<<endl;
    Studentinput->gender=gender;
 //   while(getchar()!='\n'); //Clean the buffer;
    //courseCounter:
    Studentinput->courseCounter=0;
}

void Student::operator+=(Course *coursetoadd) {
    const int newsize=this->courseCounter+1;

    //define a new arr:
    Course *newCourseList[2];
    for(int i=0;i<newsize;++i) {
        newCourseList[i]= new Course();
    }

    //check if the course is already on the list:
    for(int i=0;i<this->courseCounter;++i) {
        if(this->ArrayCoursePtr[i]==coursetoadd){
            return;
        }
    }

    //insert new array:
    //if the array is empty:
    if(this->courseCounter==0){
        newCourseList[0]=coursetoadd;
    }
    //if array not empty:
    else {
        for (int i = 0; i < newsize; ++i) {
            newCourseList[i] = this->ArrayCoursePtr[i];
        }
    }

    this->ArrayCoursePtr=newCourseList;
    this->courseCounter++;
    coursetoadd->operator+=(this);
}


void Student::operator-=(Course *Course) {
    int temp;
    bool tempreturn=false;
    for(int i=0;i<this->courseCounter;++i){
        if(this->ArrayCoursePtr[i]==Course){
            tempreturn=true;
        }
    }
    if(tempreturn==false){
        return;
    }

    else if(this->ArrayCoursePtr== NULL){
        return;
    }

    //FIND THE PLACE IN ARRAY:
    for(int i=0; i<this->courseCounter;++i){
        if(this->ArrayCoursePtr[i]==Course){
            temp=i;
        }
    }
    int size= (sizeof(this->ArrayCoursePtr)/ sizeof(*this->ArrayCoursePtr));
    class Course *temparray;
    temparray=new class Course[size-1];

    if(temp==0){
        for(int j=1;j<size;++j){
            temparray[j-1]=this->ArrayCoursePtr[j];
        }
    }
    else if(temp>0 && temp<size){
        int j=0;
        for(int i=0;i<size;++i){
            if(i!=temp){
                temparray[j]=this->ArrayCoursePtr[i];
                ++j;
            }
        }
    }
    else if(temp==size){
        for(int i=0;i<size;++i){
            temparray[i]=this->ArrayCoursePtr[i];
        }
    }
    this->ArrayCoursePtr=&temparray;
    if(this->courseCounter==1){
        this->ArrayCoursePtr= NULL;
    }
    this->courseCounter--;
    Course->operator-=(this);
}

Course *Student::operator[](int index) {
    if(this->ArrayCoursePtr== NULL){
        return NULL;
    }
    return this->ArrayCoursePtr[index];
}

