#ifndef __GRADE__
#define __GRADE__
///
 /// @file    grade.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-13 00:18:44
 ///
#include "Student_info.h" 
#include "median.h"
/*	
 * midterm		20%
 * final		40%
 * homework		40% ,计算方式采用中位数 
 *
 * */
double grade(double midterm, double finall, double homework);
double grade(double midterm, double finall, const std::vector<double>& );
double grade(Student_info& );


#endif
