 ///
 /// @file    handleString.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-02 18:12:53
 ///
 
#ifndef __HANDLESTRING_H__
#define __HANDLESTRING_H__
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

int getMaxlen(const vector<string> &v);
vector<string> frameStrings(vector<string> &usrInput);
vector<string> vcatTwoStrings(const vector<string> &, const vector<string> &);
vector<string> hcatTwoStrings(const vector<string> &, const vector<string> &);

#endif
