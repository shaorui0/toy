///
/// @file    Query.cc
/// @author  shaorui(sr1054461216@gmail.com)
/// @date    2019-08-11 20:20:44
///

#include "Query.h"
Query::Query(string cmd)
	: p_(new WordQuery(cmd)){
		cout << "Query("<<cmd<<")"<<endl;
	}
QueryResult Query::eval(const TextQuery& t) const{
	return p_->eval(t);//通过基类指针虚调用。
} 
string Query::rep() const{
	return p_->rep();
}
std::ostream& operator<<(std::ostream &os, const Query &query){
	return os<< query.rep();
}
Query operator~(const Query &rhs)
{
	return shared_ptr<QueryBase>(new NotQuery(rhs));//隐式转换,Q_B* => Query
}
Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<QueryBase>(new AndQuery(lhs, rhs));//隐式转换,Q_B* => Query
}
Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));//隐式转换,Q_B* => Query
}
//-----------------
//WordQuery

QueryResult WordQuery::eval(const TextQuery& t) const
{
	return t.query(word_);
}
QueryResult NotQuery::eval(const TextQuery& t) const
{
	//std::set_different
	//
	//get fileText
	//get fileText's size(all lines)
	//make set<line_no>
	//
	//get lhs.set<line_no>
	auto wordResult = query_.eval(t);
	auto file = wordResult.get_file();
	auto totalLinesSize = file->size();
	auto totalLines = std::make_shared<set<line_no>>();
	for (size_t i = 0; i!= totalLinesSize; ++i){
		totalLines->insert(i);
	}
	auto wordLines = std::make_shared<set<line_no>>(wordResult.begin(), wordResult.end());

	auto ret_lines = std::make_shared<set<line_no>>();
	std::set_difference(totalLines->begin(), totalLines->end(), wordLines->begin(), wordLines->end(),std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, wordResult.get_file());

}
QueryResult AndQuery::eval(const TextQuery& t) const
{
	// std::set_intersection
	//
	//get lhs.set<line_no>
	//get rhs.set<line_no>
	//
	auto left = lhs_.eval(t);
	auto right = rhs_.eval(t);
	auto left_lines = std::make_shared<set<line_no>>(left.begin(), left.end());
	auto right_lines = std::make_shared<set<line_no>>(left.begin(), left.end());
	auto ret_lines = std::make_shared<set<line_no>>(left.begin(), left.end());
	std::set_intersection(left_lines->begin(), left_lines->end(), right_lines->begin(), right_lines->end(), std::inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}
QueryResult OrQuery::eval(const TextQuery& t) const
{
	//std::set_union
	//
	//get lhs.set<line_no>
	//get rhs.set<line_no>
	auto left = lhs_.eval(t);//left's type is QueryResult
	auto right = rhs_.eval(t);
	auto ret_lines = std::make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	//std::set_union(left_lines->begin(), left_lines->end(), right_lines->begin(), right_lines->end(), std::inserter(*ret_lines, ret_lines->begin()));
	//
	//TODO:test ret_lines content
	return QueryResult(rep(), ret_lines, left.get_file());
}
