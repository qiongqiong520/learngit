 ///
 /// @file    query.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-10 10:56:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class WordQuery;//Daddy
NotQuery;//~A;ice
OrQuery;//hair|Alice，返回两个运算对象分别出现的行并集
BinaryQuery;//派生类，表示两个运算对象的查询
AndQuery;//hair&Alice

Query q =Query("fiery")&Query("bird")|Query("wind");
class Query_base
{
	//所有成员都是private
	friend class Query;
	friend line_no =TextQuery_no;//用于eval函数
	virtual ~Query_base() =default;

	private:
	//eval返回与当前query匹配的queryresult
	virtual QueryResult eval(const TextQuery&) const =0;
	//rep是表示查询的一个string
	virtual std::string rep()	const =0;
};

//query管理体系继承接口
class Query
{
	//这些运算符需要接受访问shared_ptr的构造函数，而该函数是私有的
	friend Query operator~(const Query&);
	friend Query operator|(const Query &);
	friend QUery operator&(const Query &);
	public:
	Query(const std::string &);//构建一个新的wordQuery
	//接口函数：调用对应的query_base操作
	QueryResult eval(const TextQuery &t)const
	{
		return q->eval(t);
	}
	std::string rep() const
	{
		return q->rep();
	}
	private:
	Query(std::shared_ptr<Query_base>query):q(query){}
	std::shared_ptr<Query_base>q;
};

//输出运算符用于解释怎么查询系统如何工作
std::ostream &
operator<<(std::ostream &os,const Query &query)
{//Query ::rep通过他的query_base指针对query_base 进行虚调用
	return os<<query.rep();
}

Query andq =Query(sought1)&Query(sought2);
cout<<andq<<endl;

//word_query查找一个指定类
class WordQuery:public Query_base
{
	friend class Query ; //Query使用word Qu 而已构造函数
	WordQuery(const std::string &s):query_word(s){}
	//具体的类:WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t)const
	{return t.query(query_word);}
	std::string rep()const{return query_word;}
	std::string query_word;
};

	//定义wordquery之后，接收string的query构造函数
	inline
	Query::Query(std::string &s):q(new WordQuery(s)){}

	//~运算符生成一个query，保存取反的query
class NotQuery:public Query_base
{
	friend Query operator ~(const Query &);
	//具体的类NotQuery 将定义所有继承而来的纯虚函数
	std::string rep() const
	{
		return "~("+query.rep()+")";
	}
	QueryResult eval(const TextQuery &)cosnt;
	Query query;
};
//NotQuery所有成员都是私有，一开始就需要设定为友元函数

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

//分配一个新的NotQuery对象
//将分配得到的NotQuery对象绑定到一个shared_ptr<Query_base>
shared_ptr<Query_base>tmp(new NotQuery(expr));
return query(tmp);

//BinaryQuery抽象基类，绑定两个操作运算对象的查询类型所需的数据
class BinaryQuery:public Query_base
{
	protected:
		BinaryQuery(const Query &l,Query &r,std::string s);
		//抽象类:BinaryQuery不定义eval
		std::string rep() cosnt {return  "("+lhs.rep()+" "
			+opSym+" "
				+rhs.rep()+")";}
		Query lhs,rhs;//左侧和右侧运算对象
		std::string opSym;//运算符名字
};

class AndQuery:public Query_base
{
	friend Query operator&(const Query&,const Query&);
	AndQuery(const Query &left,const Query &right):
		BinaryQuery(left,right,"&"){}
	//具体的类：AndQuery继承了rep并且定义了其他纯虚函数
	QueryResult eval(const TextQuery&)const;
};

inline Query operator &(const Query &lhs,const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query &,const Query&);
	OrQuery(const Query &left,const Quer &right):
		BinaryQuery(left,right,"|");
	QeuryResult eval(cnst TextQuery &)const;
};

inline Query operator|(const Query &lhs,const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs);
}




