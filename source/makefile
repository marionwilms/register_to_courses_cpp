Student.o : Student.h List_course.h Student.cpp
	g++ -c Student.cpp

List_account.o : Student.h List_account.h List_account.cpp
	g++ -c List_account.cpp

Course.o : Course.h Course.cpp
	g++ -c Course.cpp

List_course.o : Course.h List_course.h Student.h List_course.cpp
	g++ -c List_course.cpp

user_interface.o : Student.h List_account.h List_course.h user_interface.h user_interface.cpp
	g++ -c user_interface.cpp

main : Student.o List_account.o Course.o List_course.o user_interface.o main.o
	g++ -o main Student.o List_account.o Course.o List_course.o user_interface.o main.o
