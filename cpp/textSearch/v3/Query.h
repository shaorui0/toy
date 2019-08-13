///
/// @file    Query.h
/// @author  shaorui(sr1054461216@gmail.com)
/// @date    2019-08-07 18:27:29
///
#ifndef __QUERY_H__
#define __QUERY_H__
#include "TextQuery.h"
#include <memory>
#include <algorithm>

using std::shared_ptr;
class QueryBase{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~QueryBase()=default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

class Query{
	friend Query operator~(const Query &rhs);
	friend Query operator|(const Query &lhs, const Query &rhs);
	friend Query operator&(const Query &lhs, const Query &rhs);
public:
	Query(string cmd);
	QueryResult eval(const TextQuery& t) const;
	string rep() const;

private:
	Query(shared_ptr<QueryBase> p)//可隐式转换
	: p_(p){
		cout << "Query(shared_ptr<QueryBase> p)"<< endl;//可隐式转换
	}//支持运算符访问（具体类型由指向的对象决定）
	shared_ptr<QueryBase> p_;
};
class WordQuery 
: public QueryBase{
	friend class Query;//need access the constructor
private:
	WordQuery(string cmd)
	: word_(cmd){
		cout << "WordQuery(string cmd)"<<endl;
	}
	QueryResult eval(const TextQuery& t) const;
	string rep() const {
		return word_;
	}

	string word_;
};
class NotQuery
: public QueryBase{
	friend class Query;//need access the constructor
	friend Query operator~(const Query &);
private:
	NotQuery(const Query &q)
	: query_(q){
		cout << "NotQuery(const Query &q)"<<endl;
	}
	QueryResult eval(const TextQuery& t) const;
	string rep() const {
		return "~("+query_.rep()+")";//直接通过Query(QueryBase)进行多态(访问兄弟(WordQuery))
	}
	Query query_;//通过query_进行多态
};
class BinaryQuery: public QueryBase{
protected:
	BinaryQuery(const Query &lhs, const Query &rhs, string opsSym)
	: lhs_(lhs)
	, rhs_(rhs)
	, opSym_(opsSym){
		cout <<"BinaryQuery(const Query &lhs, Query &rhs)"<<endl;
	}

	//不定义eval，直接继承纯虚函数eval，表示此类也为抽象类，无法创建对象
	//
	string rep() const 
	{	return "("+lhs_.rep()+opSym_+rhs_.rep()+")";}

	Query lhs_, rhs_;//通过query_进行多态
	string opSym_;

};
class OrQuery 
: public BinaryQuery{

	friend class Query;//need access the constructor
	friend Query operator|(const Query &, const Query&);
private:
	OrQuery(const Query &lhs, const Query &rhs)
	: BinaryQuery(lhs, rhs, "|"){
		cout << "OrQuery(const Query &lhs, const Query &rhs)"<<endl;
	}
	QueryResult eval(const TextQuery& t) const;
};
class AndQuery
: public BinaryQuery{

	friend class Query;//need access the constructor
	friend Query operator&(const Query &, const Query&);
private:
	AndQuery(const Query &lhs, const Query &rhs)
	: BinaryQuery(lhs, rhs, "&"){
	
		cout << "AndQuery(const Query &lhs, const Query &rhs)"<<endl;
	}
	QueryResult eval(const TextQuery& t) const;
};
#endif
