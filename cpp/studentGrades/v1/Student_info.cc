 ///
 /// @file    Student_info.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-13 00:48:34
 ///
 
#include "Student_info.h"
#include "grade.h"

double Student_info::grade() const
{
	return ::grade(midterm, finall, homework);	
}
std::istream Student_info::read_hw(std::istream& in, std::vector<double>& )
{

}
std::istream Student_info::read(std::istream& in, Student_info&)
{

}
