#ifndef __STUDENT_INFO__
#define __STUDENT_INFO__
 ///
 /// @file    Student_info.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-13 00:18:33
 ///
 
#include <string>
#include <vector>
#include <iostream>
class Student_info{

public:
	std::string name(){
		return name_;
	}
	double grade() const;
	std::istream read(std::istream& in, Student_info&);
private:
	std::istream read_hw(std::istream& in, std::vector<double>& );
	
	std::string name_;
	double midterm, finall;
	std::vector<double> homework;

};

bool compare(Student_info& , Student_info& );
#endif
