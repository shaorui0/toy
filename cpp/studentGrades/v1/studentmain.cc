 ///
 /// @file    studentmain.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-13 00:31:05
 ///
 
#include "median.h"
#include "grade.h"
#include "Student_info.h"
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(void)
{
	//declare students
	vector<Student_info> students;
	
	//read students' info
	Student_info record;
	while(read(cin, record)){
		students.push_back(record);	
	}
	//check students' size
	//if size == 0
		//print some message
	if (students.size() == 0) {
		cout << "please input some students' infomations\n";
	}
	
	//sort
	std::sort(students.begin(), students.end(), compare);
	//output sorted grades
	for (auto iter = students.begin(); iter != students.end(); ++iter) {
		cout << iter->name() << " : "
			 << iter->grade()<<endl;
	}

	return 0;
}
