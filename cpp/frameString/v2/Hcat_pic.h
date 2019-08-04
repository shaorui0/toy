 ///
 /// @file    Hcat_pic.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 19:34:08
 ///
 
#ifndef __HCAT_PIC__
#define __HCAT_PIC__
#include "Basic_pic.h"
#include "Ptr.h"
class Picture;
class Hcat_pic
: public Basic_pic{
	friend Picture hcat(const Picture&, const Picture&);

private:
	Hcat_pic(const Ptr<Basic_pic>& left, const Ptr<Basic_pic>& right)
	: left_(left)
	, right_(right)
	{}

	size_t getWidth();
	size_t getHeight();
	std::ostream& display(std::ostream &, size_t, bool );

	Ptr<Basic_pic> left_, right_;
};

#endif
