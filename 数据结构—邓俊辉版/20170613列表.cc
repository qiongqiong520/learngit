 ///
 /// @file    20170613列表.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-13 21:09:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//3.7ListNode::insertAsPred算法
template<typename T>//将e仅靠当前节点之前插入与当前节点所属的列表(设有哨兵节点header
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e){
	ListNodePosi(T) x =new ListNode(e,pred,this);//创建新节点
	pred->succ=x;pred=x;
	return x;//返回新节点的位置
}
//3.8后插入操作
template<typename T>//将e紧随当前节点插入与当前节点所属的列表
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e){
	ListNodePosi(T)x=new ListNode(e,this,succ);//创建新节点
	succ->pred=x;succ=x;//设置逆向链接
	return x;//返回新节点位置
}

//3,9列表内部方法实现
template<typename T>//列表方法：复制方法中位置p起的n项
void List<T>::copyNodes(ListNodePosi(T) p,int n){//p合法，切至少有n-1个真后继节点
	init();//创建头尾哨兵并作初始化
	while(n--){insertAsLast(p->data);p=p->succ;}//将起自p的n项一次作为莫节点插入
}

//3.10基于复制的列表构造方法
template<typename T>//复制类表中自位置p起的n项（assert：p位置合法，切至少有n-1个后记节点
List<T>::List(ListNodePosi(T)p,int n){copyNodes(p,n);}
template<typename T>//整体复制列表L
List<T>::List(List<T> const& L){copyNodes(L.first(),L._size);}

template<typename T>//复制L中自第r项起的n项(assert:R+n<+L._size)
List<T>::List(List<T> const& L,int r,int n){copyNodes(L[r],n);}

//3.11列表节点删除接口remove()
template<typename T>T List<T>::remove(ListNodePosi(T) p){//删除合法节点p，返回其数值
	T e=p->data;//备份带删除节点的数值,嘉定T类型可直接复制
	p->pred->succ =p->succ;p->succ->pred=p->pred;//后继，前驱
	delete p;_Size--;//释放节点，更新规模
	return e;//返回备份的数值
}
//析构函数
template<typename T>List<T>::~List()//列表析构器
{
	clear();delete header;delete trailer;//清空列表，释放头尾哨兵节点
}

//3.13列表清空方法clear
template<typename T>int List<T>::clear(){//清空列表
	int oldSize=_size;
	while(0<_size)remove(header->succ);//反复删除首节点，直至列表变空
	return oldSize;
}
//3.14无序列表删除重复节点接口
template<typename T>int List<T>::deduplicate();{//剔除无序列表中的重复节点
	if(_size<2)return 0;//平凡列表自然重复
	int oldSize=_size;//纪录愿规模
	ListNodePosi(T)p=header;Rank r=0;//p从首节点开始
	while(trailer !=(p=p->succ)){//依次直到末节点
		ListNodePosi(T)q=find(p->data,r,p);//在p的r个真前驱中查找雷同着
		q?remove(q):r++;//若的确存在，则删除之，否则秩加一
	}//循环过程中的任意时刻，p的所有前驱互不相同
	return oldSize-_size;//列表规模变化量，即被删除元素总数
}

//3.15列表遍历接口trailer
template<typename T>void List<T>::traverse(void (*visit)(T&))//借助函数指针机制遍历
{
	for(ListNodePosi(T)p=header->succ;p!=trailer;p=p->succ)visit(p->data);
}
template<typename T> template<typename VST>//元素类型，操作器
void List<T>::traverse(VST& visit)//借助函数对象机制遍历
{for(ListNodePosi(T) p=header->succ;p!=trailer;p=p->succ)visit(p->data);}


//3.16有序列表剔除重复节点接口uniquify
template<typename T>int List<T>::uniquify(){//成批剔除重复元素，效率更高
	if(_size<2)return 0;//平凡列表自然无重复
	int oldSize=_size;//纪录原规模
	ListNodePosi(T)p=first();ListNodePosi(T)q;//p为各区段起点，q为其后继
	while(trailer!=(q=q->succ))//反复考察紧邻的节点对（p,q)
		if(p->data!=q->data)p=q;//若互异，则转向下一区段
		else remove(q);//否则雷同，删除后者
	return oldSize-_size;//列表规模变化量，即被删除元素总数
}
//3.17有序列表查找接口search
template<typename T>//在有序列表内节点p的n个真前驱中，找不到大于e的最后者
ListNodePosi(T) List<T>::search(T const& e,int n,ListNodePosi(T)p)const{
	while(0<=n--)//对于p的最近的n个前驱，从右向左逐个比较
		if(((p=p->pred)->data)<=e)break;//直至命中，数值越界户范围越界
	//至此位置p必符合输出予以约定，尽管此前最后一次关键码比较可能没有意义
	return p;//返回查找终止的位置
}//失败时，返回区间左边界 的前驱
//3.18有序列表基于排序的构造方法
template<typename T>void List<T>::sort(ListNodePosi(T) p,int n){//列表u 见排序
	switch(rand()%3){//随机选取排序算法，可根据具体问题的特点灵活选取或扩充
		case 1:insertionSort(p,n);break;//插入排序
		case 2:selectionSort(p,n);break;//选择排序
		default:mergeSort(p,n);break;//归并排序
	}
}

//3.19列表的插入排序
template<typename T>//列表的插入排序算法:对起始位置p的n个元素排序
void List<T>::insertionSort(ListNodePosi(T) p,int n){//valid
	for(int r=0;r<n;r++){//逐一为各节点
		insertA(search(p->data,r,p),p->data);//查找适当的位置病插入
		p=p->succ;remove(p->pred);//转向下一节点
	}
}
