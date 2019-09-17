//
// Created by adel on 19/11/18.
//
#include <iostream>
#include <string>
#include "Course.h"

using namespace std;



Course::Course() {
    string init = "";
    Course_ID = init;
    Title = init;
    Teacher = init;
    Location = init;
    nbStudent = 0;
}

Course::Course(string co_id, string co_title, string co_teacher, string co_location) {
    Course_ID = co_id;
    Title = co_title;
    Teacher = co_teacher;
    Location = co_location;
    nbStudent = 0;
}

void Course::show() const {
    cout << "Course_ID: " << Course_ID << endl << "Title: " << Title << endl << "Teacher:" << Teacher << endl << "Location:" << Location << endl << endl;
}