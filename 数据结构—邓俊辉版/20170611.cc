 ///
 /// @file    20170611.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-11 22:24:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//ListNode模版
typedef int Rank;
#define ListNodePosi(T) ListNode<T>*//列表节点位置

template <typename T> struct ListNode{//可别熬节点模板累
	//成员
	T data;ListNodePosi(T)pred;ListNodePosi(T) succ;//数值，前驱，后继
	//构造函数
	ListNode(){}//针对header和trailer构造
	ListNode(T e,ListNodePosi(T) pNULL,ListNodePosi(T)succ=NULL)
		:data(e),pred(p),succ(s){}//默认构造函数
	//操作接口
	ListNodePosi(T)insertAsPred(T const& e);
	ListNodePosi(T)insertAsSucc(T const& e);//紧随当前节点之后插入新节点
};

//List模板类
#include"listNode.h"

template <typename T>class List{
	private:
		int _size;
		ListNodePosi(T) header;
		ListNodePosi(T) trailer;
	protected:
		void init();
		int clear();
		void copyNodes(ListNodePosi(T),int);
		void merge(ListNodePosi(T),int,List<T>&,ListNodePosi(T),int);//归并
		void mergeSort(ListNodePosi(T),int);//对从p开始连续的nb格节点归并排序
		void selectionSrt(ListNodePosi(T),int);//对从p开始连续的n格节点选择排序
		void insertionSort(ListNodePosi(T),int);//对从p开始的连续n格节点插入排序
		
	public:
		//构造函数
		List(){init();}
		List(){List<T> const& L;}//整体复制列表
		List(List<T>const& L,Rank r,int n);//赋值列表中L中自第r项开始的n项 
		List(ListNodePosi(T),int n);//赋值列表中自位置p起的n项
		//析构函数
		~List();//释放（包含头，尾梢兵在内的所有节点
		//只读访问接口
		Rank size()const{return _size;}//规模
		bool empty()const{return _size<=0;}//判空
		T& operator[](Rank r)const;//重载，支持循秩访问(效率低)
		ListNodePosi(T)first() const{return header->succ;}//首节点位置
		ListNodePosi(T)last()const{return header->pred;}//末节点位置
		bool valid(ListNodePosi(T) p);//判断位置p是否对外合法
		{
			return p&&(trailer!=p)&&(header!=p);}//将头尾节点等同于null
		}
		int disordered() const;//判断列表是否已经排序
		ListNodePosi(T)find(T const& e)const//无序列表查找
		{return find(e,_size,trailer);}
		ListNodePosi(T)find(T const& e,intn,ListNodePosi(T) p)const;//无需区间查找
		ListNodePosi(T)search(T const& e,int n,ListNodePosi(T) p)const;//有序区间查找
		ListNodePosi(T)search(T const& e,int n,ListNodePosi(T) p,int n,ListNodePosi(T) p)const;
		ListNodePosi(T)selectMax(ListNodePosi(T) p,int  n);//在p及其1n-1个后继中选出最大者
		ListNodePosi(T)selectMax(){return selectMax(header->succ,_size);}//整体最大者
		//可写访问接口
		ListNodePosi(T)insetAsFirst(T const& e);//将e当作首节点
		ListNodePosi(T)insetAsLast(T const& e);//将e当作莫节点插入
		ListNodePosi(T)insertA(ListNodePosi(T) p,T const& e);//将e当作p的后记节点
		ListNodePosi(T)insertB(ListNodePosi(T) p,T const& e);//将e当作p的前驱节点插入
		T remove(ListNodePosi(T) p);//删除合法位置p处的节点，返回被删除节点位置
		void merge(List<T>& L){merge(first(),size ,L,L.first(),L._size);}//       全列表归并
		void sort(ListNodePosi(T) p,int n);//列表区间排序
		void sort(){sort(first(),_size);}//列表整体排序
		int deduplicate();//无序去重
		int uniquify();//有序去重
		void reverse();//前后倒置
		//遍历
		void traverse(void(*)(T&));//遍历。一次实时visit操作(函数指针,只读或局部性修改)
		template <typename VST>//操作器
		void traverse(VST&);//遍历,依次实施visit操作函数对象可全局修改
		};//List

//双向链表
template<typename T>void List<T>::init(){??列表初始化，在创建类表对象是同一调用
	header=new ListNode<T>;;//创建头节点哨兵
	trailer = new ListNode<T>;//创建尾节点哨兵
	header->succ = trailer;header->pred=NULL;
	trailer->pred=header;trailer->succ=NULL:
		_size=0;//记录规模
}

//由秩到位置转换
template<typename T>//重载下表操作符，已通过秩直接访问列表节点，虽然方便，单效率比较低
T& List<T>::operator[](Rank r)const{
	ListNodePosi(T) p =first();//while(0<r--)p=p->succ;
	return p->data;
}
template<typename T>//在无序列表节点中
ListNodePosi(T) p=first();//首节点出发
while(0<r--)p=p->succ;//顺数第r个节点既是
return p->data;//目标节点,返回其中所存元素
}
template<typename T>//在无序列表内节点排（kenneltrailer）的n个前驱中找到等于e的最后者
ListNodePosi(T)List<T>::find(T const& e,int n,ListNodePosi(T) p)const{
	while(0<n--)
		if(e==(p=p->pred)->data)return p;//诸葛对比，直至命中或范围越界
	return NULL;
}//失败时，返回NULL；

//接口
template<typename T>ListNodePosi(T)List<T>::insertAsFirst(T const& e)
{_size++;return header->insertAsSucc(e);}//e当作首节点插入

template<typename T>ListNodePosiList<T>::insertAsLast(T const& e)
{_size++;return trailer->insertAsPred(e);}

template<typename T>ListNodePosiList<T>::insertA(ListNodePosi(T) p,T const& e)
{_size++;return p->insertAsSucc(e);}//e当作p的后记节点插入after
template<typename T>ListNodePosi(T)List<T>::insertB(ListNodePosi(T) p,T const& e)
{_size++;return p->insertAsPred(e);}//e当作p的前驱节点插入before

template<typename T>//将e仅靠当前节点之前插入鱼当前节点所属的累额表
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e){
	ListNodePosi(T) x=new ListNode(e,pred,this);//创建新节点
	pred->succ=x;pred=x;//设置正向链接
	return x;//返回断点位置
}

