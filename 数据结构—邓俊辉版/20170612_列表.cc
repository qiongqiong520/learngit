 ///
 /// @file    20170612_列表.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-12 21:08:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//listnode模板类
typedef int Rank;//秩
#define ListNodePosi(T) ListNode<T>* //列表节点位置

template <typename T>struct ListNode{//列表节点模板类（以双向链表形式实现
	//成员
	T data;ListNodePosi pred;ListNodePosi(T) succ;//数值，前驱，后继
	//构造函数
	ListNode(T e,ListNodePosi(T) p=NULL,ListNodePosi(T)  s=NULL)
		:data(e),pred(p),succ(s){}//默认构造函数
	//操作接口
	ListNodePosi(T)insertAsPred(T const& e);//紧靠当前节点之前插入新节点
	ListNodePosi(T)insertAsSucc(T const& e);//紧随当前节点之后插入新的节点
};

//List模板类
#include"listNode.h"
template<typename T>class List{//列表模板类
	private:
		int _size;ListNodePosi(T)header;ListNodePosi(T)trailer;//规模，头哨兵，尾哨兵
	protected:
		void init();//列表创建时的初始化
		int clear();//清除所有节点
		void copyNodes(ListNodePosi(T)& ,int ,List<T>&,ListNodePosi(T),int);//对从p开始连续的n个节点归并排序
		void merge(ListNodePosi(T)&,int,List<T>&,ListNodePosi(T),int);//归并
		void mergeSort(ListNodePosi(T)&,int);//对从p开始连续的n个节点归并排序
		void selectionSort(ListNodePosi(T),int);//对从p开始连续的n个节点选择排序
		void insertionSort(ListNodePosi(T),int);//对从p开始连续的n个节点插入排序

		public：
			//构造函数
			List(){init();}//默认
		List(List<T> const& L);//整体复制列表L
		List(List<T> const& L,Rank r,int n);//复制列表L中自第r项起的n项
		List(ListNodePosi(T) p,int n);//复制列表中的位置p起的n项
		//构造函数
		～List();//释放包含头，尾哨兵所有节点
		//只读访问接口
		Rank size() const{return _size;}//规模
		bool empty()const {return _size<=0;}//判空
		T& operator[](Rank r)const;//重载，支持循秩访问（效率低）
		ListNodePosi(T) first()const{return header->succ;}//首节点位置
		LsitNodePosi(T) last() const{return trailer->pred;}//末节点位置
		bool valid(ListNodePosi(T)p)//判断位置p是否合法
		{return p&& (trailer!=p)&&(header!=p);}//将头尾节点等同于NULL
		int disordered()const;//判断列表是否已经排序
		ListNodePosi(T) find(T const& e)const//无序查找列表
		{return find(e,_size,trailer);}
		ListNodePosi(T)search(T const& e,int n,ListNodePosi(T) p)const;//无序区间查找
		ListNodePosi(T) selectMax(ListNodePosi(T) p,int n);//在p及其后n-1个后继中选出最大的
		ListNOdePosi(T) selectMax(){return selectMax(header->succ,_size);}//整体最大者
		//可写访问接口
		ListNodePosi(T)insertAsFirst(T const& e);//将e当作首节点插入
		ListNodePosi(T) insertAsLast(T const& e);//将e当作莫节点插入
		ListNodePosi(T) insertA(ListNodePosi(T) p,T const& e);//将e当作p的后继节点插入
		ListNodePosi(T) insertB(ListNodePosi(T) p,T const& e);//将e当作p的前驱节点插入
		T remove(ListNodePosi(T) p);//删除合法位置p处的节点，返回别删除的节点
		void merge(ListNodePosi(T) p);//删除合法位置p处的节点，返回别删除节点
		void merge(List<T>& L){merge(first(),size,L,L.first(),L._size);}//全列表归并
		void sort(ListNodePosi(T)p,int n);//列表区间排序
		void sort(){sort(first(),_size);}//列表整体排序
		int deduplicate();//无序去重
		int uniquify();//有序去重
		void reverse();//前后倒置
		//遍历
		void traverse(void(*)(T&));//遍历，依次实施visit操作（函数指针，只读或局部性修改）
		template<typename VST>//操作器
			void traverse(VST&);//遍历，一次实现visit 操作（函数对象，课全局修改)
};//List

template<typename T>void List<T>::init(){//列表初始化，在创建列表对象时统一调用
	header =new ListNode<T>;//创建头哨兵节点
	trailer =new ListNode<T>;//创建尾哨兵节点
	header->succ= trailer;header->pred=NULL;
	trailer->pred=header;trailer->succ = NULL;
	_size= 0;//纪录规模
}

template<typename T>//重载下标操作符，已通过直接访问的列表节点
T& List<T>::operator[] (Rank r)const{//assert:0<=r<size
	ListNodePosi(T)p=first();//从首节点出发
	while(0<r--)p =p->succ;//顺数第r个元素节点
	return p->data;//目标节点，返回其中的所存元素
}

template<typename T>//在无序列表内节点p（可能是trailer)的n个（真前驱中，找到等于e的最后者
ListNOdePosi(T) List<T>::find(T const& e,int n,ListNodePosi(T)p)const{
	while(0<n--)//对于p的最近n个前驱，从右向左
		if(e==(p=p->pred)->data)return p;//诸葛对比，直至命中或范围越界
	return NULL;//p越出左边界意味着区间内不含e，查找失败
}//失败时，返回NULL

template<typename T>ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{_size++;return header->insertAsSucc(e);}//e当作首节点插入

template<typename T> ListNodePosi(T) List<T>::insertAsLast(T const& e)
{_size++;return trailer->insertAsPred(e);}//e当作莫节点插入

template<typename T>ListNodePosi(T)::insertA(ListNodePosi(T) p,T const& e)
{_size++;return p->insertAsSucc(e);}//e当作p的后继插入after
template<typename T>ListNodePosi(T)List<T>::insertB(ListNodePosi(T) p,T const& e)
{_size++;return p->insertAsPred(e);}//d当作p的前驱插入before

template<typename T>//将e仅靠当前节点之前插入所属列表（设有哨兵节点header)
ListNodePosi(T)ListNode<T>::insertAsPred(T const& e){
	ListNodePosi(T)x=new ListNode(e,pred,this);//创建新节点
	return x;//返回新节点的位置
}
//后插入操作
template<typename T>//将e紧随当前节点之后插入所属列表
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e){
	ListNodePosi(T)x=new ListNode(e,this,succ);//创建新节点
	succ->pred=x;succ=x;//设置逆向链接
return x;//返回新节点位置
}

//基于复制构造函数
template<typename T>//列表内部方法：复制列表中自位置起的n项
void List<T>::copyNodes(ListNodePosi(T) p,int n){//p合法，切至少有n-1个真后继节点
	init();//创建头节点,尾哨兵节点并做比较
	while(n--){insertAsLast(p->data);p=p->succ;}//将起自p的n项议程作为莫节点插入
}
template<typename T>//复制列表中自位置p起的n项（assert：p为合法位置，切至少有n-1个后记节点
List<T>::List(ListNodePosi(T) p,int n){copyNodes(p,n);}

template<typename T>//整体复制列表l
List<T>::List(List<T> const& L){copyNodes(L.first(),L._size);}

template<typename T>//复制L中自dir项起的n项
List<T>::List(List<T> const& L,int r,int n){copyNodes(L[r],n);}

//删除


