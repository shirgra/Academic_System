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
#include "AcademicInstitute.h"

int main() {

    AcademicInstitute BGU=AcademicInstitute();
    AcademicInstitute* ptrBGU=&BGU;

    BGU.menu();

    return 0;
}
