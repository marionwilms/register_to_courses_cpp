//
// Created by adel on 19/11/18.
//

#include "List_course.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include <fstream>
#include <map>

using namespace std;


List_Course::List_Course() {
    nb = 0;
}

void List_Course::add_Course(Course& co) {
    if (co.get_nb() <10) {
        pair<string, Course> nouvElem(co.get_id(), co);
        list_course.insert(nouvElem);
        nb++;
        co.inc_nb();
    }
    else {
        cout << "cours complet"<<endl;
    }
}


void List_Course::show() const {
    map<string,Course>::const_iterator it;
    for (it = list_course.begin(); it != list_course.end(); it++){
        it->second.show();
    }
}


void lecture_Courses(List_Course& LC) {
    ifstream file("Course.txt");
    bool fin = false;
    string course_id;
    string course_title;
    string course_teacher;
    string course_location;
    while (fin == false) {
        file >> course_id >> course_title >> course_teacher >> course_location;
        if (file.eof() == true) {
            fin = true;
        } else {
            Course C(course_id, course_title, course_teacher, course_location);
            pair<string, Course> nouvElem(course_id, C);
            LC.list_course.insert(nouvElem);
            LC.nb++;
        }
    }
}
