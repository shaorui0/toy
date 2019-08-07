 ///
 /// @file    QueryResult.h
 /// @author  shaorui(sr1054461216@gmail.com)
 /// @date    2019-08-06 20:05:01
 ///
 
#ifndef __QUERY_RESULT__
#define __QUERY_RESULT__

#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <set>
using std::vector;
using std::shared_ptr;
using std::map;
using std::set;
using std::string;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;

class QueryResult{
	//friend ostream& operator<<(ostream&, QueryResult&);
	friend ostream& print(ostream& os, const QueryResult& ret);
public:
	QueryResult(string queryword, 
			shared_ptr<set<int>> lines,
			shared_ptr<vector<string>> lineText)
		  : queryWord_(queryword)
		  , lines_(lines)
		  , lineText_(lineText)
		  {
		  }
private:
	//所谓result，你需要显示的信息，其他通通不需要
	string queryWord_;
	shared_ptr<set<int>> lines_;
	shared_ptr<vector<string>> lineText_;
};

#endif
