 ///
 /// @file    Basic_pic.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-03 18:25:32
 ///

#ifndef __BASIC_H__
#define __BASIC_H__
#include <iostream>


/* 无需此类的对象，仅作为抽象基类接口*/
class Picture;
class Basic_pic{
	friend std::ostream &operator<<(std::ostream&, const Picture);
	friend class Frame_pic;
	friend class String_pic;
	friend class Hcat_pic;
	friend class Vcat_pic;
	friend class Picture;
public:
	virtual size_t getWidth()=0;
	virtual size_t getHeight()=0;
	virtual void display(std::ostream &, size_t, bool )=0;
	
	virtual 
	void reframe(char topAndBottom, char leftAndRight, char corner)=0;
protected:
	static void pad(std::ostream& os, size_t start, size_t end)//无需继承，实现相同
	{
		//pad space with index line in ostream
		while (start != end){
			os << " ";
			++start;
		}
	}
};
#endif
