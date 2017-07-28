 ///
 /// @file    avl_macro.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-15 17:04:53
 ///
 /*
  * 在左右孩子中去更高者
  * 在AVl平衡调整之前，借此确定重构方案
  */
#define tallerChild(x)(\
		stature((x)->lc)>stature((x)->rc)?(x)->lc:(/*左高*/\
			stature((x)->lc)<stature((x)->rc)?(x)->rc:(/*右高*/\
				IsLChild(*(x))?(x)->lc:(x)->rc/*等高:与父亲x同侧者(zlg-zlg或zag-zAg)有限*/\
				)\
			)\
		)
