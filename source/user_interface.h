//
// Created by adel on 16/11/18.
//

#ifndef PROJET_UML_USER_INTERFACE_H
#define PROJET_UML_USER_INTERFACE_H
#pragma once

#include <iostream>
#include <string>
#include "Student.h"
#include "List_account.h"
#include "List_course.h"

using namespace std;


class user_interface {
public:

    friend class Student;

    user_interface();

    void principal_menu(List_Account &LA, List_Course &LC);

    bool login_menu(List_Account &LA, List_Course &LC);

    bool login(List_Account &LA, string login_id, string psd);

    bool is_in_list(List_Account &LA, string login_id);

    void create_student_file(Student& st); //create a txt file to save the courses of a student

    void add_course_to_file();

    bool file_exist(); //check if we already created a student file

    void lecture_Courses_from_student_file();


    void student_menu(List_Course &LC, List_Account &LA);

    Course available_course_menu(List_Course &LC);

    Student set_student(List_Account &LA, string login_id, string psd);

    void add_course_to_planning(Course &co);



private:
    Student st;
};


#endif //PROJET_UML_USER_INTERFACE_H
