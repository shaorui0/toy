 ///
 /// @file    grade.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-13 00:49:03
 ///
 
#include "grade.h"


double grade(double midterm, double finall, double homework)
{
	return 0.2 * midterm + 0.4 * finall + homework * 0.4;
}
double grade(double midterm, double finall, const std::vector<double>& homework)
{
	return grade(midterm, finall, median(homework));
}
double grade(Student_info& student)
{
	return student.grade();
}
