//
// Created by adel on 16/11/18.
//

#include "user_interface.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "List_account.h"
#include "List_course.h"

using namespace std;


user_interface::user_interface() {}

void user_interface::principal_menu(List_Account &LA, List_Course &LC) {
    int choice = 0;
    cout << "********** Administrator ISMIN Course Selection System *******************" << endl;
    cout << "1- Login" << endl;
    cout << "2- Quitter" << endl;
    cin >> choice;
    if (choice == 1) {
        while (!login_menu(LA, LC)) {
            login_menu(LA, LC);
        }
    } else {
        exit(0);
    }
}


bool user_interface::login_menu(List_Account &LA, List_Course &LC) {
    string id, psd;
    Student st;
    cout << "Please enter your id: " << endl;
    cin >> id;
    cout << "Password : " << endl;
    cin >> psd;
    if (!login(LA, id, psd)) {
        cout << "Id or password incorrect. Try again." << endl;
        return false;
    } else {
        st = set_student(LA, id, psd);
        cout << "--------- Welcome to your profile " << st.get_first_name() << " " << st.get_last_name()
             << ". -------------------" << endl;
        if (file_exist()) {
            lecture_Courses_from_student_file();
            student_menu(LC,LA);
        } else {
            create_student_file(st);
            student_menu(LC, LA);
        }
        return true;

    }
}

bool user_interface::login(List_Account &LA, string login_id, string psd) {
    map<string, Student>::const_iterator it2;
    for (it2 = LA.get_map().begin(); it2 != LA.get_map().end(); it2++) {
        if (login_id == it2->second.get_login_id() && psd == it2->second.get_login_psd()) {
            Student s = it2->second;
            return true;
        }
    }
    return false;
}

Student user_interface::set_student(List_Account &LA, string login_id, string psd) {
    map<string, Student>::const_iterator it2;
    for (it2 = LA.get_map().begin(); it2 != LA.get_map().end(); it2++) {
        if (login_id == it2->second.get_login_id() && psd == it2->second.get_login_psd()) {
            return it2->second;
        }
    }
}


void user_interface::student_menu(List_Course &LC, List_Account &LA) {
    int choice = 0;
    int choice2 = 0;
    cout << "********** Administrator ISMIN Course Selection System *******************" << endl;
    cout << "1- Check Planning" << endl;
    cout << "2- Browse available course" << endl;
    cout << "3- Logout" << endl;
    cin >> choice;
    if (choice == 1) {
        List_Course student_courses = st.get_list_course();
        if (st.get_nbCourses() == 0) {
            cout << "No courses subscribed" << endl;
        } else {
            student_courses.show();
        }
        cout << "1- Remove a course" << endl;
        cout << "2- Return to menu" << endl;
        cin >> choice2;
        if (choice2 == 1) {
            if (st.get_nbCourses() == 0) {
                cout << "no course subscribed" << endl;
                student_menu(LC, LA);
            } else {
                string id;
                cout << "enter the id of the course" << endl;
                cin >> id;
                map<string, Course>::iterator it = st.get_list_course().get_list_cours().find(id);
                if (it != st.get_list_course().get_list_cours().end()) {
                    st.get_list_course().get_list_cours().erase(it);
                    st.dec_nbCourses();
                    student_menu(LC, LA);
                }
                it = LC.get_list_cours().find(id);
                it->second.dec_nb();


            }
        } else {
            student_menu(LC, LA);
        }
    } else if (choice == 2) {
        if (st.get_nbCourses() < 4) {
            Course co = available_course_menu(LC);
            add_course_to_planning(co);
        } else {
            cout << "You have too many courses." << endl;
        }
        student_menu(LC, LA);
    } else if (choice == 3) {
        add_course_to_file();
        principal_menu(LA, LC);
    }
}


Course user_interface::available_course_menu(List_Course &LC) {
    int cpt = 1;
    string choice;
    map<string, Course> list_cours = LC.get_list_cours();
    map<string, Course>::iterator it;
    for (it = list_cours.begin(); it != list_cours.end(); it++) {
        if (it->second.get_nb() < 10) {
            cout << "- " << cpt << endl;
            it->second.show();
            cpt++;
        }
    }
    cout << "Choose a course:" << endl;
    cin >> choice;
    for (it = list_cours.begin(); it != list_cours.end(); it++) {
        if (it->second.get_id() == "CCMP2A-00" + choice) {
            return it->second;
        }
    }
}


bool user_interface::is_in_list(List_Account &LA, string login_id) {
    map<string, Student>::const_iterator it2;
    for (it2 = it2 = LA.get_map().begin(); it2 != LA.get_map().end(); it2++) {
        if (login_id == it2->second.get_login_id()) {
            return true;
        }
    }

    return false;
}



void user_interface::add_course_to_planning(Course &co) {
    st.set_list_cours(co);
    st.inc_nbCourses();
}


void user_interface::create_student_file(Student& st) {
    string file_name = st.get_first_name() + st.get_last_name() + ".txt";
    ofstream file(file_name, ios::app);
}

void user_interface::add_course_to_file() {
    List_Course student_courses = st.get_list_course();
    string file_name = st.get_first_name() + st.get_last_name() + ".txt";
    ofstream file(file_name);
    map<string, Course> list_cours = student_courses.get_list_cours();
    map<string, Course>::const_iterator it;
    for (it = list_cours.begin(); it != list_cours.end(); it++) {
        file << it->second.get_id() << " " << it->second.get_Title() << " " << it->second.get_Teacher() << " "
             << it->second.get_Location() << endl;
    }

}

bool user_interface::file_exist() {
    string file_name = st.get_first_name() + st.get_last_name() + ".txt";
    ifstream file(file_name);
    if (file) {
        return true;
    } else
        return false;
}


void user_interface::lecture_Courses_from_student_file() {
    string file_name = st.get_first_name() + st.get_last_name() + ".txt";
    List_Course student_courses = st.get_list_course();
    ifstream file(file_name);
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
            st.set_list_cours(C);
            st.inc_nbCourses();
        }
    }

}
