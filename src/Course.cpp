/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#include <iostream>
#include "Course.h"
#include "Student.h"
using namespace std;


Course::Course() {
	this->name;
	this->number;
	this->studentCounter=0;
	//link to courses:
	this->ArrayStudentPtr= new Student*[0];
	//link to grades:
	this->Grades= NULL;
}


Course::~Course() {
}

void Course::setnumber(int number) {
	this->number=number;
}

void Course::setname(string nameinput) {
	this->name=nameinput;
}


//Get:
string Course::getname() {
	return this->name;
}

int Course::getnumber(){
	return this->number;
}
Student ** Course::getstudents(){
	return this->ArrayStudentPtr;
}
int** Course::getgrades() {
	return this->Grades;
}
int Course::getstudentcounter(){
	return this->studentCounter;
}


void Course::operator=(Course* Course2) {
	this->number=Course2->number;
	this->name=Course2->name;
	this->studentCounter=Course2->studentCounter;
	this->ArrayStudentPtr=Course2->ArrayStudentPtr;
}

bool Course::operator==(Course *Course2) {
	bool tempbool=false;
	if(this->number==Course2->number){
		tempbool= true;
	}
	return tempbool;
}

bool Course::operator>(Course *Course2) {
	bool tempbool=false;
	if(this->studentCounter>Course2->studentCounter){
		tempbool= true;
	}
	return tempbool;
}

ostream &operator<<(ostream &out, Course *Courseoutput) {
	cout<<"Printing Course:"<<endl;
	cout<<"Name: "<<Courseoutput->name<<endl;
	cout<<"Number: "<<Courseoutput->number<<endl;
	cout<<"Number of Students: "<<Courseoutput->studentCounter<<endl;
	cout<<"Students and Grades:"<<endl;
	for(int i=0;i<Courseoutput->studentCounter;++i){
		cout<<"Student "<<i<<" :";
		cout<<Courseoutput->ArrayStudentPtr[i]->getname()<<", ";
		cout<<Courseoutput->ArrayStudentPtr[i]->getid()<<", ";
		cout<<Courseoutput->ArrayStudentPtr[i]->getgender()<<", ";
		cout<<"Grade:"<<*(Courseoutput->getgrades()[i])<<endl;
	}
}

istream &operator>>(istream &in, Course *Courseinput) {
	string name;
	int num;
	if(Courseinput== NULL){
		*Courseinput=Course();
	}

	cout<<"Input Course:"<<endl;

	//Name:
	cout<<"Please enter Name: ";
	cin>>name;
	cout<<endl;
	Courseinput->name=name;
	//    while(getchar()!='\n'); //Clean the buffer;
	//Number:
	cout<<"Please enter number: ";
	cin>>num;
	cout<<endl;
	Courseinput->number=num;
	//   while(getchar()!='\n'); //Clean the buffer;
	//student counter:
	Courseinput->studentCounter=0;
}

void Course::operator+=(Student *Student) {

	int temp=-1;
	class Student *temparray= nullptr;
	int **tempgrades=nullptr;
	for(int i=0;i<this->studentCounter;++i){
		if(this->ArrayStudentPtr[i]==Student){
			return;
		}
	}

	if(this->ArrayStudentPtr[0]== NULL){
		this->ArrayStudentPtr=new class Student*[1];
		this->Grades=new int*[1];
		int* minus1 = new int;
		*minus1 = temp;
		this->ArrayStudentPtr[0]=Student;
		this->Grades[0]=minus1;
	}
	else{
		int size= (sizeof(this->ArrayStudentPtr)/ sizeof(*this->ArrayStudentPtr));
		temparray = new class Student[size + 1];
		tempgrades= new int*[size+1];
		for(int i=0;i<size;++i){
			temparray[i]=this->ArrayStudentPtr[i];
			tempgrades[i]=this->Grades[i];
		}

		delete[]this->ArrayStudentPtr;
		delete[]this->Grades;

		temparray[size]=Student;
		this->ArrayStudentPtr=&temparray;
		int* minus1 = new int ;
		*minus1 = temp;
		tempgrades[size]=minus1;
		this->Grades=tempgrades;
	}
	this->studentCounter++;
	Student->operator+=(this);
}

void Course::operator-=(Student *Student) {
	int temp; //index in list
	bool tempreturn=false;
	for(int i=0;i<this->studentCounter;++i){
		if(this->ArrayStudentPtr[i]==Student){
			tempreturn=true;
		}
	}
	if(tempreturn==false){
		return;
	}
	else if(this->ArrayStudentPtr==NULL){
		return;
	}

	//FIND THE PLACE IN ARRAY:
	for(int i=0; i<this->studentCounter;++i){
		if(this->ArrayStudentPtr[i]==Student){
			temp=i;
		}
	}
	int size= (sizeof(this->ArrayStudentPtr)/ sizeof(*this->ArrayStudentPtr));
	class Student *temparray;
	int *tempintarr;
	temparray=new class Student[size-1];
	tempintarr=new int[size-1];


	if(temp==0){
		if(this->studentCounter==1){
			temparray= NULL;
			tempintarr= NULL;
		}
		else{
			for(int j=1;j<size;++j){
				temparray[j-1]=this->ArrayStudentPtr[j];
				tempintarr[j-1]=*this->Grades[j];
			}
		}
	}
	else if(temp>0 && temp<size){
		int j=0;
		for(int i=0;i<size;++i){
			if(i!=temp){
				temparray[j]=this->ArrayStudentPtr[i];
				tempintarr[j]=*this->Grades[j];
				++j;
			}
		}
	}
	else if(temp==size){
		for(int i=0;i<size;++i){
			temparray[i]=this->ArrayStudentPtr[i];
			tempintarr[i]=*this->Grades[i];

		}
	}

	delete[]this->ArrayStudentPtr;
	delete[]this->Grades;

	this->ArrayStudentPtr=&temparray;
	this->Grades=&tempintarr;

	if(this->studentCounter==1){
		this->ArrayStudentPtr[0]= NULL;
		this->Grades[0]= NULL;
	}

	this->studentCounter--;
	Student->operator-=(this);
}

Student *Course::operator[](int index) {
	if(this->ArrayStudentPtr== NULL){
		return NULL;
	}
	return this->ArrayStudentPtr[index];
}


