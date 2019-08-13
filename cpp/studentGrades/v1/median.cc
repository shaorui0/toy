 ///
 /// @file    median.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-13 00:54:17
 ///
 
#include "median.h"
#include <algorithm>

template <class T>
T median(std::vector<T>& homework)
{
	typedef std::vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0)
		return 0;
	std::sort(homework.begin(), homework.end());
	return size%2==0 ? (homework[size/2]+homework[size/2+1]) /2 : homework[size/2];
}
