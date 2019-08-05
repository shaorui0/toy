 ///
 /// @file    Hcat_pic.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 19:34:08
 ///
 
#ifndef __HCAT_PIC__
#define __HCAT_PIC__
#include "Basic_pic.h"
#include "Ptr.h"
class Hcat_pic
: public Basic_pic{
	friend Picture hcat(const Picture&, const Picture&);
	friend class Picture;
private:
	Hcat_pic(const Ptr<Basic_pic>& left, const Ptr<Basic_pic>& right)
	: left_(left)
	, right_(right)
	{}

	size_t getWidth()
	{	return left_->getWidth() + right_->getWidth(); }
	size_t getHeight()
	{	return std::max(left_->getHeight(), right_->getHeight());	}
	void display(std::ostream &, size_t, bool );

	Ptr<Basic_pic> left_, right_;
};

#endif
void Hcat_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	//稍微要处理一下 left'height < right's height的情况
	left_->display(os, lineNum, toFillSpace||lineNum<right_->getHeight());//超过了也补space, width*" "
	right_->display(os, lineNum, toFillSpace);
}
