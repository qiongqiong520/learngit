 ///
 /// @file    query.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-10 10:56:59
 ///
 
#include<string>
#include <iostream>
#include<memory>
#include<vector>
#include<set>
#include<map>
#include<iterator>//迭代器
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::vector;
using std::set;
using std::map;
using std::cin;

using line_no =vector<string>::size_type;
class QueryResult//为了定义函数query的返回类型，这个定义是必须的
{
	//扩展查询系统，在queryresult中
	//添加begin和end'成员，返回一个迭代器
	//指向一个给定的查询返回的行号的set中的位置
	//添加一个名为getfile的成员，返回一个shared_ptr,指向Query——Result对象中的文件
  	 friend std::ostream& print(std::ostream&,const QueryResult&);

	public:
	QueryResult(std::string s,
  			std::shared_ptr<std::set<line_no> > p,
			std::shared_ptr<std::vector<std::string> > f):
	sought(s),lines(p),file(f){}//继承基类列表
	void get_file()
	{
		return <shared_ptr>file;
	}
	auto begin(),end();
	private:
	std::string sought;//查询单词
	std::shared_ptr<std::set<line_no> > lines;//输入文件
	std::shared_ptr<std::vector<std::string> > file;
};
class TextQuery
{
   	  public:
  	 	using line_no =vector<string>::size_type;
		TextQuery(std::ifstream &);
		QueryResult query(const string &)const;
	private:
   		shared_ptr<vector<string> >file;//输入文件
		//每个单词到她所在行号的集合的映射
		map<string,shared_ptr<set<line_no> > >wm;

};

//TextQuery的构造函数接收一个ifstream函数，逐行读取输入文件

//读取输入文件并建立单词到行号的映射
TextQuery::TextQuery(std::ifstream &is):file(new vector<string>)
{
	string text;
	string word,line;
	while(getline(is,text)){//读文件中的每一行
  		file->push_back(text);//保存此行文本
		int n =file->size()-1;//当前行号
		std::istringstream line(text);//将行文本分解为单词
		while(line>>word){//对行中每个单
 			//如果不在wm中，以之为下标在wm中添加一个项
			auto &line = wm[word];//line是一个shared_ptr；
			if(!line)//在我们第一次遇到这个单词时，此指针为空
				line.reset(new set<line_no>);//分配一个新的set
			line->insert(n);//将此行号插入到set中
		}
	}
}

//设计一个类接受一个指向要处理文件的ifsream，并与用户实现交互，打印给定单词的查询结果

void runQueries(std::ifstream &infile)
{
	 //infile 是一个ifstream,指向我们要处理的文件
	TextQuery tq(infile);//保存文件并建立查询
	//与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while(true)//字面常量
	{
 		cout<<"enter word to llok for,or q to quit:";
		string s;
		//如欲动文件尾或用户输入了'q'时终止循环
		if(!(cin>>s)||s=="q")break;
		//指向打印查询结果
		print(cout,tq.query(s))<<endl;
	}
}

QueryResult
TextQuery::query(const string &sought)const
{
	//如果未找到sought,我们将返回一个指向此的set指针
	static shared_ptr<set<line_no>>nodata(new set<line_no>);
	//使用find而不是下标运算符来查找单词，避免将单词添加到wm中
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought,nodata,file);//未找到
	else
		return QueryResult(sought,loc->second,file);
}
//如果ctr的值大于1，返回word的复数形式
string make_plural(size_t ctr,const string &word,const string &ending)
{
	return (ctr>1)?word+ending:word;
}

//打印结果
std::ostream &print(std::ostream & os,const QueryResult & qr)
{
 	//如果找到单词，打印出现的次数和所有出现的位置
	os<<qr.sought<<"occurs "<<qr.lines->size()<<" "
		<<make_plural(qr.lines->size(),"time","s")<<endl;//make_plural根据大小是否等于1来打印time或times
	//打印每行单词出现位置
	for(auto num:*qr.lines)//set中的每个单词
 		os<<"\t(line"<<num+1<<")"
			<<*(qr.file->begin()+num)<<endl;
	return os;
}

//Query q =Query("fiery")&Query("bird")|Query("wind");
class Query_base
{
	//所有成员都是private
	friend class Query;
	protected:
	using line_no =TextQuery::line_no;//用于eval函数
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
	friend Query operator~(const Query &);//取反
	friend Query operator|(const Query&,const Query&);//或操作
	friend Query operator&(const Query&,const Query&);//与操作
	public:
	Query(const std::string &);//构建一个新的wordQuery
	//接口函数：调用对应的query_base操作
	QueryResult eval(const TextQuery &t) const
	{
		return q->eval(t);
	}
	std::string rep() const
	{
		return q->rep();
	}
	private:
	Query(std::shared_ptr<Query_base>query):q(query){}
	std::shared_ptr<Query_base> q;
};

//query输出运算符用于解释怎么查询系统如何工
std::ostream &
operator<<(std::ostream &os,const Query &query)
{//Query ::rep通过他的query_base指针对query_base 进行虚调用
	return os<<query.rep();
}
#if 0
Query andq =Query(sought1)&Query(sought2);
cout<<andq<<endl;
#endif

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
	Query::Query(const std::string &s):q(new WordQuery(s)){}

	//~运算符生成一个query，保存取反的query
class NotQuery:public Query_base
{
	friend Query operator ~(const Query &);
	//具体的类NotQuery 将定义所有继承而来的纯虚函数
	NotQuery(const Query &q):query(q){}
	std::string rep() const
	{
		return "~("+query.rep()+")";
	}
	QueryResult eval(const TextQuery&) const;
	Query query;
};
//NotQuery所有成员都是私有，一开始就需要设定为友元函数

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

//分配一个新的NotQuery对象
//将分配得到的NotQuery对象绑定到一个shared_ptr<Query_base>
//shared_ptr<Query_base>tmp(new NotQuery(expr));
//return query(tmp);

//BinaryQuery抽象基类，绑定两个操作运算对象的查询类型所需的数据
class BinaryQuery:public Query_base
{
 	protected:
 		BinaryQuery(const Query &l,const Query &r,std::string s)
			:lhs(l),rhs(r),opSym(s){}

		//抽象类:BinaryQuery不定义eval
		std::string rep()const {return  "("+lhs.rep()+" "+ opSym +" " 	+rhs.rep()+")";}
		Query lhs,rhs;//左侧和右侧运算对象
		std::string opSym;//运算符名字
};

class AndQuery:public BinaryQuery
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
	OrQuery(const Query &left,const Query &right):
		BinaryQuery(left,right,"|"){}
	QueryResult eval(const TextQuery &)const;
};

inline Query operator|(const Query &lhs,const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

//返回运算对象查询结果set的并集
QueryResult
OrQuery::eval(const TextQuery& text)const
{
	//通过Query成员lhs和rhs进行虚调用
	//调用通过eval返回每个运算对象的queryreslut
	auto right =rhs.eval(text);
	auto left = lhs.eval(text);
	//将左侧运算对象的行号拷贝到所得结果set中
	auto ret_lines = std::make_shared<set<line_no>>(left.begin(),left.end());
	//插入右侧运算对象所得符号
	ret_lines->insert(right.begin(),left.end());
	//返回一个新的queryREsult，他表示lhs和rhs的并集
	return QueryResult(rep(),ret_lines,left.get_file());
	}

	//AndQuery:eval调用标准哭算法来求得两个查询结果中共有的行
	QueryResult
	AndQuery::eval(const TextQuery& text)const
{
	//通过query运算对象进行的虚调用，以获得运算对象查询结果set
	auto left=lhs.eval(text),right =rhs.eval(text);
	//保存left和right交集的set
	auto ret_lines = std::make_shared<set<line_no>>();
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
	auto ret_lines =std::make_shared<set<line_no>>();
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


