 ///
 /// @file    query.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-10 10:56:59
 ///
 
#include <iostream>
#include<string>
#include<memory>
#include<vector>
using std::cout;
using std::endl;
using std::string;
using std:shared_ptr;
using std::vector;
using std::set;


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

//返回运算对象查询结果set的并集
QueryResult
OrQuery::eval(const TextQuery& text)const
{
	//通过Query成员lhs和rhs进行虚调用
	//调用通过eval返回每个运算对象的queryreslut
	auto right =rhs.eval(text),left = lhs.eval(text);
	//将左侧运算对象的行号拷贝到所得结果set中
	auto ret_lines = 
	make_shared<set<line_no>>(left.begin(),left.end());
	//插入右侧运算对象所得符号
	ret_line->insert(right.begin(),left.end());
	//返回一个新的queryREsult，他表示lhs和rhs的并集
	return QueryResult(rep(),ret_lines,left.get_file());
	}

	//AndQuery:eval调用标准哭算法来求得两个查询结果中共有的行
	QueryResult
	AndQuery::eval(const TextQuery& text)const
{
	//通过query运算对象进行的虚调用，以获得运算对象查询结果set
	quto left=lhs.eval(text),right =rhs.eval(text);
	//保存left和right交集的set
	auto ret_lines = make_shared<set<ine_no>>();
	//将两个范围的交集写入一个目的迭代器中
	//本次调用的目的迭代器想ret添加元素
	set_intersection(left.begin(),left.begin(),
			right.begin().right.end(),
			inserter(*ret_lines,ret_lines->begin()));
	return QueryResult(rep(),ret_lines,left,get_file());
}

//NotQuery查找运算对象没有出现在文本行
QueryResult
NotQuery::eval(const TextQuery &text)const
{
	//通过query运算对象对eval进行虚调用
	auto result =query.eval(text);
	//开始时结果set为空
	auto ret_lines =make)shared<set<lines_no>>();
	//我们必须在运算对象出现的所有文本行中进行迭代
	auto beg=result.begin(),end=result.end();
	//对于输入文件中的每一行，如果改行不再result中，则将其添加到ret_lines中
	auto sz=result.get_file()->size();
	for(size_t n=0;n!=sz;++n){
		//如果我们还没有处理完result的所有行
		//检查当前昂是否存在
		if(beg==end||*beg!=n)
			ret_lines->insert(n);//如果不在result中，添加这一行
		else if(beg!=end)
			//否则继续获取result的下一行（如果有的话）
	}
	return QueryResult(rep(),ret_lines,result.get_file());
}


//设计一个类接受一个指向要处理文件的ifsream，并与用户实现交互，打印给定单词的查询结果

void runQueries(ifstream &infile)
{
	//infile是一个ifstream,指向我们要处理的文件
	TextQuery tq(infile);//保存文件并建立查询
	//与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while(true)//字面常量
	{
		cout<<"enter word to llok for,or q to quit:";
		strng s;
		//如欲动文件尾或用户输入了'q'时终止循环
		if(!(cin>>s)||s=="q")break;
		//指向打印查询结果
		print(cout,tq.query(s))<<endl;
	}
}

class QueryResult;//为了定义函数query的返回类型，这个定义是必须的
class TextQuery
{
	public:
		using line_no =vector<string>::size_type;
		TextQuery(std:ifstream);
		QueryResult query(const string &)const;
	private:
		shared_ptr<vector<string>>file;//输入文件
		//每个单词到她所在行号的集合的映射
		map<string,shared_ptr<set<line_no>> wm;
};

//TextQuery的构造函数接收一个ifstream函数，逐行读取输入文件

//读取输入文件并建立单词到行号的映射
TextQuery::TextQuery(ifstream &is):file(new vector<String>)
{
	string text;
	while(getline(is,text)){//读文件中的每一行
		file->push_back(text);//保存此行文本
		int n =file->size()-1;//当前行号
		istringstream line(text);//将行文本分解为单词
		while(line>>word){//对行中每个单
			//如果不在wm中，以之为下标在wm中添加一个项
			auto &line =wm(word);//line是一个shared_ptr；
			if(!lines)//在我们第一次遇到这个单词时，此指针为空
				lines.reset(new set<line_no>);//分配一个新的set
			lines->insert(n);//将此行号插入到set中
		}
	}
}




