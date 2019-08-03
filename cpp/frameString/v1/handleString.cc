 ///
 /// @file    handleString.cc
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-02 18:06:23
 ///
 
#include "handleString.h"
#include <algorithm>
 
int getMaxlen(const vector<string> &v)
{
	if (v.size() == 0) 
		return 0;
	int maxlen = -1;
	for (size_t i =0; i < v.size(); ++i){
		//get current string's size
		int curLen = v[i].size();
		//if longer than max len, 
		if (curLen > maxlen)
			maxlen = curLen;
			//update max len
		//endif
	}
	//return max length of strings
	return maxlen;
}
vector<string> frameStrings(vector<string> &usrInput)
{
	/* Frame the user input strings by '*' */
	vector<string> framedStr;
	//get strings max length
	size_t len = getMaxlen(usrInput);
	//add top frame, length+2(' ')+2('*')
	framedStr.push_back(string(len+4, '*'));
	//add left frame, cat '*' and vector[i]
	if (usrInput.size() == 0)
		framedStr.push_back("*  *");

	for (size_t i = 0; i != usrInput.size(); ++i) { 
		//get right fill space number
		int fillNum  = len - usrInput[i].size();
		framedStr.push_back("* " + usrInput[i] + string(fillNum, ' ') + " *"); 
	}
	//add right frame by max length :* xxx *, cat vector[i] and some ' ' and '*'
	//add bottom frame
	framedStr.push_back(string(len+4, '*'));
	//add left frame, cat '*' and vector[i]

	//return framed strings
	return framedStr;
}
vector<string> vcatTwoStrings(const vector<string> &lhs, const vector<string> &rhs)
{
	vector<string> ret;
	ret = lhs;
	/*
	for (size_t i = 0; i!= rhs.size(); ++i) {
		ret.push_back(rhs[i]);
	}
	*/
	for (auto iter = rhs.begin(); iter != rhs.end(); ++iter)
		ret.push_back(*iter);
	return ret;

}
#if 0
vector<string> hcatTwoStrings(const vector<string> &lhs, const vector<string> &rhs)
{
	vector<string> ret;
	//get larger number by comparing these strings.
	int leftNumber = lhs.size();
	int rightNumber = rhs.size();
	int retNumber = std::max(leftNumber, rightNumber);

	//get two max wides of the two strings.//getMaxlen()
	int leftWide = getMaxlen(lhs);
	//int rightWide = getMaxlen(rhs);
	
	//if left strings's size larger than right, easy to cat
	/*
	 *  asdasd		bdasdasdasdbbb
	 *  asdasdasdas cccasdfa
	 *  as			sfdafd
	 *  asdasda
	 *
	 * */
	if (leftNumber > rightNumber) {
		//cat left and right strings
		for (size_t i = 0; i!= rightNumber; ++i) {
			ret.push_back(lhs[i] + string(leftWide - lhs[i].size(), ' ')+ " " + rhs[i]);
		}
		//cat left strings and some spaces
		for (size_t j = rightNumber+1; j != retNumber; ++j) {
			//ret.push_back(lhs[j]); //不应该是push_back，应该是 +=，在同一行进行操作	
		}
	}
	//else, fill wide_1 spaces in left and cat right string after finish left vector size 
	/*
	 *  asdasd		bdasdasdasdbbb
	 *  asdasdasdas cccasdfa
	 *  as			sfdafd
	 *				dasdasdasdas 
	 *				sdfsdfsdfsdf
	 * */
	else {
		//cat left and right strings
		for (size_t i = 0; i!= leftNumber; ++i) {
			ret.push_back(lhs[i] + string(leftWide - lhs[i].size(), ' ')+ " " + rhs[i]);
		}
		//cat some spaces and right strings
		for (size_t j = leftNumber+1; j != retNumber; ++j) {
			ret.push_back(string(leftWide+1, ' ') + rhs[j]);
		}
		
	}	
	// 以上代码违反了DRY！！！  
	//endif
	//return cated strings 
}
#endif
//Case1: left strings' number > right is easy
//Case2: left strings' number < right, 
vector<string> hcatTwoStrings(const vector<string> &lhs, const vector<string> &rhs)
{
	vector<string> ret;
	//get left strings' max width
	int leftWidth = getMaxlen(lhs);
	//KEY POINT: left string + filled spaces + right string
	//while left or right string exist
	int i = 0, j = 0;
	while(i != lhs.size() || j != rhs.size()){
		string s;
		//if left exist, cat tmpStr and left string
		if (i!= lhs.size())
			s += lhs[i++];
		//cat tmpStr and fill spaces
		s += string(leftWidth-s.size(), ' ');
		//if right exist, cat tmpStr and right string
		if (j!= rhs.size())
			s += rhs[j++];
		//push in ret
		ret.push_back(s);
		//
	}
	return ret;





	return ret;
}
