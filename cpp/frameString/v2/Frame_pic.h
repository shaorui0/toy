 ///
 /// @file    Vcat_pic.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 19:34:08
 ///
 
#ifndef __FRAME_H__
#define __FRAME_H__
#include "Basic_pic.h"
#include "Ptr.h"
class Picture;
class Frame_pic 
: public Basic_pic{
	friend Picture frame(const Picture&);

private:
	Frame_pic(const Ptr<Basic_pic>& framed)//实现多态
	: framed_(framed)
	{}

	size_t getWidth();
	size_t getHeight();
	std::ostream& display(std::ostream &, size_t, bool );

	Ptr<Basic_pic> framed_;

};

#endif
