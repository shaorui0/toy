 ///
 /// @file    TextQuery.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-05 01:41:07
 ///
 
#include <stdio.h>
#include <string>
#include <map>
#include <set>
using std::map;
using std::set;
using std::string;

 
class TextQuery{
public:
	TextQuery(string filename, string queryWord)
	: filename_(filename)
	, queryWord_(queryWord){}


private:
	string filename_;
	string queryWord_;

	map<string, set<int>> wordLines_;
	map<string, int> wordFrequency_;
	map<int, string> lineText_;
};
int main(void)
{
 
}
