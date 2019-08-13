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
	typedef vector<string>::size_type line_no;
	typedef	set<line_no>::const_iterator line_iter; 
	QueryResult(string queryword, 
			set<line_no>* lines,
			vector<string>* lineText)
		  : queryWord_(queryword)
		  , lines_(lines)
		  , lineText_(lineText)
		  {
		  }
	QueryResult(const QueryResult& qr){

	}
	QueryResult(const QueryResult&&){

	}
	line_iter begin(){
		return lines_->begin();
	}
	line_iter end(){
		return lines_->end();
	}
	std::vector<std::string>* get_file() const{ return lineText_; }
private:
	//所谓result，你需要显示的信息，其他通通不需要
	string queryWord_;
	set<line_no>* lines_;
	vector<string>* lineText_;
};

#endif
