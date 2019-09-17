#include <iostream>
#include <string>
#include <fstream>
#include "user_interface.h"
#include "List_account.h"
#include "List_course.h"
#include "Student.h"
#include "Course.h"
using namespace std;

int main() {
    List_Account L;
    create_list(L);
    user_interface U;
    List_Course C;
    lecture_Courses(C);
    U.principal_menu(L, C);


    return 0;
}
