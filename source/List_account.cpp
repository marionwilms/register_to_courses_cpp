//
// Created by adel on 16/11/18.
//

#include <iostream>
#include <string>
#include "Student.h"
#include <fstream>

#include "List_account.h"

using namespace std;


List_Account::List_Account() {
    nb = 0;
}

void List_Account::add_account(Student& st) {
    pair<string, Student> nouvElem(st.get_id(), st);
    list_account.insert(nouvElem);
    nb++;
}


void List_Account::show() const {
    map<string,Student>::const_iterator it2;
    for (it2 = list_account.begin(); it2 != list_account.end(); it2++){
        it2->second.show();
    }
}

void create_list(List_Account& LA) {
    ifstream file("Account.txt");
    bool fin = false;
    string account_id;
    string account_first_name;
    string account_last_name;
    string account_login_id, account_login_psd;
    while (fin == false) {
        file >> account_id >> account_first_name >> account_last_name >> account_login_id >> account_login_psd;
        if (file.eof() == true) {
            fin = true;
        } else {
            Student S(account_id, account_first_name, account_last_name, account_login_id, account_login_psd, 0);
            pair<string, Student> nouvElem(account_id, S);
            LA.list_account.insert(nouvElem);
            LA.nb++;
        }
    }
}
