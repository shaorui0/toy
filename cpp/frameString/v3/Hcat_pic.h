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
	void reframe(char topAndBottom, char leftAndRight, char corner);

	Ptr<Basic_pic> left_, right_;
};

#endif
#if 0
void Hcat_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	//稍微要处理一下 left'height < right's height的情况
	left_->display(os, lineNum, toFillSpace||lineNum<right_->getHeight());//超过了也补space, width*" "
	right_->display(os, lineNum, toFillSpace);
}
#endif
void Hcat_pic::display(std::ostream &os, size_t lineNum, bool toFillSpace)
{
	//get left's height and right's
	size_t l_height = left_->getHeight();
	size_t r_height = right_->getHeight();
	bool flag;
	int relativeHeight;
	if (l_height > r_height){
		flag = 0;
		relativeHeight = l_height-r_height;
	}
	else{
		flag = 1;
		relativeHeight = r_height-l_height;
	}
	relativeHeight =(int)relativeHeight/2;
	//call display with relative line number
	//if left'height > righs'height
	/*if (lineNum < relativeHeight) {
		if (!flag) {
			left_->display(os, lineNum, toFillSpace);
		}else{
			pad(os, 0, left_->getWidth());
			right_->display(os, lineNum, toFillSpace);
		}
	}else if(lineNum)	*/
		if (!flag){//left picture higher
			left_->display(os, lineNum, toFillSpace);
			if ((lineNum-relativeHeight)>=0)
				right_->display(os, lineNum-relativeHeight, toFillSpace);
		}
		else{ 
			if ((lineNum-relativeHeight)>=0)
				left_->display(os, lineNum-relativeHeight, toFillSpace||lineNum<right_->getHeight());
			else
				pad(os, 0, left_->getWidth());
			right_->display(os, lineNum, toFillSpace);
		}

	//[0, relative) line pad spaces
	//[relative,  relative+right's height) display
	//[relative+right's height, left's height) pad spaces

	
}
void Hcat_pic::reframe(char topAndBottom, char leftAndRight, char corner)
{
	left_->reframe(topAndBottom, leftAndRight, corner);
	right_->reframe(topAndBottom, leftAndRight, corner);
	
}
