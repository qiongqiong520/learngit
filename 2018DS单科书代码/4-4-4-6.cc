 ///
 /// @file    4-4-4-6.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-28 07:47:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//由孩子兄弟链表表示的树，求高度的算法思想，采用递归算法，若树为空，高度为零；否则高度为第一子女高度加1和兄弟子树高度大者，其非递归算法使用队列，逐层遍历数，取得树的高度
int Height(CSTree bt){
	//递归求解以孩子兄弟链表表示的树的深度
	int hc,hs;
	if(bt==NULL)
		return 0;
	else{//否则，高度取子女高度+！和兄弟子树的高度的大者
		hc=height(bt->firstchild);//第一子女树高
		hs=height(bt->nextsibling);//兄弟树高
		if(hc+1>hs)
			return hc+!;
		else
			return hs+1;
	}
}

//由孩子兄弟链表表示树的深度
int hc,hs;
if(bt==NULL)
	return 0;
	else{//否则，高度取子女高度+1和兄弟子树高度的大者
		hc=height(b->firstchild);//第一子女树高
		hs=height(bt->nextsibling);//兄弟树高
		if(hc+1>hs)
			return hc+1;
		else
			return hs+1;
	}
}

//由孩子兄弟链表表示树的高度
int hc,hs;
if(bt==NULL)
	return 0;
	else{//否则，高度去子女高度+1盒兄弟孩子树高度的最大者
		hc=height(bt->firstchild);//第一子女树高
		hs=height(bt->nextsibling);//兄弟树高
		if(hc+1>hs)
			return hc+1;
		else
			return hs+1;
	}
}

//由孩子兄弟链表表示的树，求高度的算法思想:采用递归算法，若树为空，高度为零，否则高度为第一子女树高+1盒兄弟子树高度的大者，采用
//非递归算法使用队列，逐层遍历树，取得树的高度
int Height(CSTree bt){
	//递归求以孩子兄弟链表表示树的高度
	int hc,hs;
	if(bt==NULL)
		return 0;
	else{//否则，高度取子女高度+1和兄弟子树高度的大者
		hc=height(bt->firstchild);//第一子女树高
		hs=height(nextsibling);//兄弟子树高度
		if(hc+1>hs)
			return hc+1;
		else
			return hs+1;
	}
}

