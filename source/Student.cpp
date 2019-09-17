//
// Created on 16/11/18.
//
#include <iostream>
#include "Student.h"
#include "List_course.h"

using namespace std;



Student::Student() {
    string init = "";
    first_name = init;
    last_name = init;
    login_id = init;
    login_psd = init;
    nbCourse = 0;
}

Student::Student(string st_id, string st_first_name, string st_last_name, string st_login_id, string st_login_psd, int nb) {
    id = st_id;
    first_name = st_first_name;
    last_name = st_last_name;
    login_id = st_login_id;
    login_psd = st_login_psd;
    nbCourse = nb;
}

void Student::show() const {
    cout << "Student_id: " << id << endl << "First Name: " << first_name << endl << "Last Name: " << last_name << endl;
}
