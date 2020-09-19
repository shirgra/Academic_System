/* Assignment: 1
Author1: Tal Toboul,
ID: 311431118
Author2: Shir Granit,
ID: 205531445
 */

#include <string>
#include <iostream>

using namespace std;
#include "Student.h"
#include "Course.h"
#include "Departmant.h"
#include "AcademicInstitute.h"


AcademicInstitute::AcademicInstitute() {
	this->name;
	this->departments= new Department*[0];
	this->depcounter=0;

	this->allstudents= new Student*[0];
	this->allstucounter=0;

	this->damagedstudents= new Student*[0];
	this->damstucounter=0;
}

AcademicInstitute::~AcademicInstitute() {

}

void AcademicInstitute::setname(string name) {
	this->name=name;
}

string AcademicInstitute::getname() {
	return this->name;
}

Department **AcademicInstitute::getdepartment() {
	return this->departments;
}

Student **AcademicInstitute::getALLstudents() {
	return this->allstudents;
}

Student **AcademicInstitute::getDAMstudents() {
	return this->damagedstudents;
}


void AcademicInstitute::menu() {

	int choice=-1;


	do{

		//Menu:
		cout<<"Welcome to menu! please select a choice by typing a number (e.g. 3):"<<endl;
		cout<<"1. Add Department"<<endl;
		cout<<"2. Add Course to department"<<endl;
		cout<<"3. Add student to department"<<endl;
		cout<<"4. Register student to course"<<endl;
		cout<<"5. Grading students in course"<<endl;
		cout<<"6. Print course information"<<endl;
		cout<<"7. Print student information"<<endl;
		cout<<"8. Print department information"<<endl;
		cout<<"9. Remove student from course"<<endl;
		cout<<"10. Exit"<<endl;
		cin>>choice;

		switch(choice){
		case 1:
			AddDepartment();
			break;

		case 2:
			AddCoursetodepartment();
			break;

		case 3:
			AddStudenttodepartment();
			break;

		case 4:
			RegisterStudentToCourse();
			break;

		case 5:
			GradingStudentsInCourse();
			break;

		case 6:
			PrintCourseInformation();
			break;

		case 7:
			PrintStudentInformation();
			break;

		case 8:
			PrintCDepartmentInformation();
			break;

		case 9:
			RemoveStudentfromCourse();
			break;

		case 10:
			break;

		default:
			cout<<"PLEASE ENTER VALID INPUT";
			break;
		}
	}
	while(choice!=10);
	cout << "Goodbye, Menu ended.";

}


//FUNCTIONS FOR MENU:

void AcademicInstitute::AddDepartment(){


	cout<<"ADD DEPARTMENT:"<<endl;
	//define:
	Department **ptryourdep;
	Department *yourdep=new Department();
	//input name:
	cout<<"Name:";
	string mystr;
	cin >> mystr;
	yourdep->setname((string)mystr);
	//  while(getchar()!='\n'); //Clean the buffer;

	//input code:
	cout<<"Department Code:";
	string code;
	cin >> code;
	yourdep->setdepcode((string)code);


	//Add another spot in Dep list:
	class Department *temparr;
	//check for doubles:
	for(int i=0;i<this->depcounter;++i){
		if(this->departments[i]==yourdep){
			return;
		}
	}
	//if empty:
	if(this->departments[0]== NULL){
		ptryourdep=new class Department*[1];
		ptryourdep[0]=yourdep;
	}
	//if not empty
	else{
		int size= (sizeof(this->departments)/ sizeof(*this->departments));
		temparr=new class Department[size+1];
		for(int i=0;i<size;++i){
			temparr[i]=this->departments[i];
		}

		temparr[size]=yourdep;
		delete[]this->departments;
		ptryourdep=&temparr;

	}
	this->depcounter++;
	cout<<"//DEPARTMENT added to INSTITUTE, returning to Menu...//:"<<endl;
	this->departments=ptryourdep;

}


void AcademicInstitute::AddCoursetodepartment() {
	cout<<"ADD COURSE TO DEPARTMENT:"<<endl;
	//define:
	Department *yourDep;
	//    Course **ptryourcourse;
	Course *yourCourse=new Course();

	//input code:
	cout<<"Please enter Department code:";
	string code;
	cin >> code;
	//   while(getchar()!='\n'); //Clean the buffer;
	bool depexist=false;

	//wait for good input:
	while(depexist==false) {
		for (int i = 0; i < this->depcounter; ++i) {
			if (this->departments[i]->getcode() == code) {
				depexist = true;
				yourDep=this->departments[i];
			}
		}
		if (depexist == false) {
			cout << "Department Does not exist,reenter the Department code:";
			cin>>code;
			//          while(getchar()!='\n'); //Clean the buffer;
		}
	}

	//input code:
	cout<<"Please enter Course number:";
	int num;
	cin>>num;
	//  while(getchar()!='\n'); //Clean the buffer;
	cout << endl;
	bool couseexist= false;

	//wait for good input:
	do {
		for (int i = 0; i < yourDep->getDepCoursescounter(); ++i) {
			if (yourDep->getDepCourses()[i]->getnumber() == num) {
				couseexist = true;
				cout << "Course already exist,reenter the Course number:";
				cin >> num;
				cout << endl;
				//               while (getchar() != '\n'); //Clean the buffer;
			}
		}
	}
	while(couseexist);


	//Get course details:
	cout<<"Please enter Course name:";
	string name;
	cin>>name;
	//   while(getchar()!='\n'); //Clean the buffer;


	yourCourse->setname((string)name);
	yourCourse->setnumber(num);
	yourDep->operator+=(yourCourse);



	cout<<"//COURSE added to DEPARTMENT, returning to Menu...//:"<<endl;
}


void AcademicInstitute::AddStudenttodepartment() {
	cout<<"ADD STUDENT TO DEPARTMENT:"<<endl;
	Department *yourDep;
	Student *yourStudent=new Student();
	//input code:
	cout<<"Please enter Department code:";
	std::string code;
	cin>>code;
	//   while(getchar()!='\n'); //Clean the buffer;
	bool depexist=false;

	//wait for good input:
	while(depexist==false) {
		for (int i = 0; i < this->depcounter; ++i) {
			if (this->departments[i]->getcode() == code) {
				depexist = true;
				yourDep=this->departments[i];
			}
		}
		if (depexist == false) {
			cout << "Department Does not exist,reenter the Department code:";
			cin>>code;
			//            while(getchar()!='\n'); //Clean the buffer;

		}
	}

	//input code:
	cout<<"Please enter Student id number:";
	int id;
	cin>>id;
	//   while(getchar()!='\n'); //Clean the buffer;

	cout << endl;

	for (int i = 0; i < yourDep->getDepStudentsCounter(); ++i) {
		if (yourDep->getDepStudents()[i]->getid() == id) {
			return;
		}
	}

	//get student detail:
	cout << "Adding new student, enter Student name:";
	std::string namestu;
	cin>>namestu;
	cout << endl;
	//    while(getchar()!='\n'); //Clean the buffer;
	cout << endl;

	cout << "Enter gender: (e.g. F)";
	char g;
	cin >> g;
	//    while(getchar()!='\n'); //Clean the buffer;

	yourStudent->setid(id);
	yourStudent->setname(namestu);
	yourStudent->setgender(g);

	yourDep->operator+=(yourStudent);

	cout<<"//STUDENT added to DEPARTMENT, returning to Menu...//:"<<endl;
}


void AcademicInstitute::RegisterStudentToCourse() {
	cout<<"REGISTER STUDENT TO COURSE:"<<endl;
	Department *yourDep;
	Course *ptryourCourse;
	Student *ptryouStudent;

	//input code:
	cout<<"Please enter Department code:";
	string code;
	cin>>code;
	//    while(getchar()!='\n'); //Clean the buffer;
	bool depgood=false, coursegood= false, studentgood=false;

	//check dep:
	for (int i = 0; i < this->depcounter; ++i) {
		if (this->departments[i]->getcode() == code) {
			depgood = true;
			yourDep=this->departments[i];
		}
		if (!depgood){
			cout<<"this department does not exsit"<<endl;
			return;
		}
	}

	//check course:
	cout<<"Please enter course number:";
	int num;
	cin>>num;
	//    while(getchar()!='\n'); //Clean the buffer;
	cout << endl;

	for (int i = 0; i < yourDep->getDepCoursescounter(); ++i) {
		if (yourDep->getDepCourses()[i]->getnumber() == num) {
			ptryourCourse=yourDep->getDepCourses()[i];
			coursegood = true;
		}
		if (!coursegood){
			cout<<"this course does not exsit"<<endl;
			return;
		}
	}
	//check student:
	cout<<"Please enter Student id number:";
	int id;
	cin>>id;
	//    while(getchar()!='\n'); //Clean the buffer;
	cout << endl;

	for (int i = 0; i < yourDep->getDepStudentsCounter(); ++i) {
		if (yourDep->getDepStudents()[i]->getid() == id) {
			studentgood=true;
			ptryouStudent=yourDep->getDepStudents()[i];
		}
		if (!studentgood){
			cout<<"this course does not exsit"<<endl;
			return;
		}
	}

	//if all good:
	if(studentgood && coursegood && depgood){

		//add student to course:
		ptryourCourse->operator+=(ptryouStudent);

	}
}


void AcademicInstitute::GradingStudentsInCourse() {
	cout << "GRADING STUDENTS IN COURSE:" << endl;
	bool okinput = false;


	while (okinput == false) {

		//input course num:
		cout << "Please enter course number:";
		int num;
		cin >> num;
		//        while(getchar()!='\n'); //Clean the buffer;
		//go on all dep:
		for (int i = 0; i < this->depcounter; ++i) {
			//go on all courses in this dep:
			for (int j = 0; j < this->departments[i]->getDepCoursescounter(); ++j) {
				if (this->departments[i]->getDepCourses()[j]->getnumber() == num) {
					gradingthiscourse(this->departments[i]->getDepCourses()[j]);
					okinput = true;
				}
			}
		}
	}
}


void AcademicInstitute::gradingthiscourse(Course *course) {
    //int** tempgrades;
    //int* temp= new int;
    //tempgrades=new int*[course->getstudentcounter()];
    if (course->getstudentcounter()!=0){
        for(int i=0; i<course->getstudentcounter();++i){
            int grade;
            cout<<"enter the student grade of ";
            cout<<course->getstudents()[i]->getname()<<":"<<endl;
            cin>>grade;
            //*temp=grade;
            //int temp
            *course->getgrades()[i]=grade;
            //tempgrades[i]=temp;
        }
    }
    else{
        cout<<"there is no student in this course."<<endl;
    }
    //course->getgrades()=tempgrades;
}



void AcademicInstitute::PrintCourseInformation() {
	cout<<"PRINTING COURSE INFORMATION:"<<endl;
	bool okinput=false;


	while(!okinput) {

		//input course num:
		cout << "Please enter course number:";
		int num;
		cin >> num;
		//        while(getchar()!='\n'); //Clean the buffer;
		cout << endl;

		//go on all dep:
		for (int i = 0; i < this->depcounter; ++i) {
			//go on all courses in this dep:
			for (int j = 0; j < this->departments[i]->getDepCoursescounter(); ++j) {
				if (this->departments[i]->getDepCourses()[j]->getnumber() == num) {
					cout << "DAPERTMENT Name:" << this->departments[i]->getname();
					cout << ", Code:" << this->departments[i]->getcode() << endl;
					Course *ptrcourse;
					ptrcourse = this->departments[i]->getDepCourses()[j];
					cout << ptrcourse;
					okinput = true;
				}
			}
		}
		if (!okinput) {
			cout << "Please enter a valid course number" << endl;
		}
	}
}







void AcademicInstitute::PrintStudentInformation() {
	cout<<"PRINTING STUDENT INFORMATION:"<<endl;
	bool okinput=false;


	while(!okinput) {

		//input course num:
		cout << "Please enter student id number:";
		int id;
		cin >> id;
		//        while(getchar()!='\n'); //Clean the buffer;
		cout << endl;

		//go on all dep:
		for (int i = 0; i < this->depcounter; ++i) {
			//go on all students in this dep:
			for (int j = 0; j < this->departments[i]->getDepStudentsCounter(); ++j) {
				if (this->departments[i]->getDepStudents()[j]->getid() == id) {

					cout << "DAPERTMENT Name:" << this->departments[i]->getname();
					cout << ", Code:" << this->departments[i]->getcode() << endl;
					Student *ptrstudent;;
					ptrstudent = this->departments[i]->getDepStudents()[j];
					cout << ptrstudent;
					okinput = true;
					cout << "Student Grades Average: ";

					//comp average:
					int average=0;
					//go on all courses of the student:
					for(int k=0; k<ptrstudent->getcoursecounter();++k) {
						Course *ptrcourse;
						ptrcourse=ptrstudent->getcourses()[i];
						//in the course go on all students in this course:
						for(int p=0; p<ptrcourse->getstudentcounter();++p) {
							if (ptrcourse->getstudents()[j]->getid() == id) {
								average += *(ptrcourse->getgrades()[j]);
							}
						}
					}
					if (ptrstudent->getcoursecounter()!=0){
					long averagefinal= average/ptrstudent->getcoursecounter();
					cout << averagefinal << endl;

					okinput = true;
					}
					else{
					int	averagefinal=0;
					cout << averagefinal << endl;
					okinput = true;
					}
				}
			}
		}
		if (!okinput) {
			cout << "Please enter a valid course number" << endl;
		}
	}
}



void AcademicInstitute::PrintCDepartmentInformation() {
	cout<<"PRINT DEPARTMENT INFORMATION:"<<endl;
	Department *yourDep;

	//input code:
	cout<<"Please enter Department code:";
	std::string code;
	cin>>code;
	bool depexist=false;

	//wait for good input:
	while(!depexist) {
		for (int i = 0; i < this->depcounter; ++i) {
			if (this->departments[i]->getcode() == code) {
				depexist = true;
				yourDep=this->departments[i];
			}
		}
		if (!depexist) {
			cout << "Department Does not exist,reenter the Department code:";
			cin>>code;
		}
	}

	cout << "Printing Department details:" << endl;
	cout << "Department Name:" << yourDep->getname() << endl;

	//print courses:
	for(int j=0; j<yourDep->getDepCoursescounter();++j){
		cout << "Course " << j << ":";
		cout << yourDep->getDepCourses()[j]->getname() << endl;
	}

	//print students:
	for(int k=0; k<yourDep->getDepStudentsCounter();++k){
		cout << "Student " << k << ":";
		cout << yourDep->getDepStudents()[k]->getname();
		cout << ", " <<yourDep->getDepStudents()[k]->getid() << endl;
	}

	//print problam students:
	cout << "Students with problamed Acadamic situation:"<< endl;
	for(int i=0; i<yourDep->getDepStudentsCounter();++i){
		Student *ptrstudent=yourDep->getDepStudents()[i];
		//comp average:
		int average=0;
		//go on all courses of the student:
		for(int k=0; k<ptrstudent->getcoursecounter();++k) {
			Course *ptrcourse;
			ptrcourse=ptrstudent->getcourses()[i];
			//in the course go on all students in this course:
			for(int p=0; p<ptrcourse->getstudentcounter();++p) {
				if (ptrcourse->getstudents()[p]->getid() == ptrstudent->getid()) {
					average += *(ptrcourse->getgrades()[p]);
				}
			}
		}
		long averagefinal= average/ptrstudent->getcoursecounter();

		if(averagefinal<65){
			cout << ptrstudent->getname() << ", " << ptrstudent->getid();
			cout << ": Average-" << averagefinal << endl;
		}
	}
}


void AcademicInstitute::RemoveStudentfromCourse() {
	cout<<"REMOVE STUDENT FROM COURSE:"<<endl;
	bool okcourse=false, oklink=false;
	Course *ptryourcourse= NULL;
	Student *ptryourstudent= NULL;
	int num;
	int id;


	while(!okcourse || !oklink) {
		//input course num:
		cout << "Please enter student id number:";
		cin >> id;
		//        while(getchar()!='\n'); //Clean the buffer;

		//input course num:
		cout << "Please enter course number:";
		cin >> num;
		//        while(getchar()!='\n'); //Clean the buffer;

		//checking for course exist:
		for(int i=0; i<this->depcounter;++i){
			for(int j=0; j<this->departments[i]->getDepCoursescounter();++j){
				if(this->departments[i]->getDepCourses()[j]->getnumber()==num){
					ptryourcourse=this->departments[i]->getDepCourses()[j];
					okcourse=true;
				}
			}
			for(int d=0;d<ptryourcourse->getstudentcounter();++d){
				if(ptryourcourse->getstudents()[d]->getid()==id){
					ptryourstudent=ptryourcourse->getstudents()[d];
					oklink=true;
				}
			}
		}
	}
	ptryourcourse->operator-=(ptryourstudent);
	cout << "Student Removed from Course" << endl;
}



