 ///
 /// @file    main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-15 17:18:31
 ///
#include"AVL_test.h"

template<typename T>void testAVl(int n){
	AVL<T> avl;
	while(avl.size()<n){
		T e=dice((T)n*3);//[0,3n)范围内的e
		switch(dice(3)){
			case 0:{//查找成功率<=33.3%
					   printf("Searching for");print(e);
					   printf("...\n");
					   BinNodePosi(T)& p=avl.search(e);
					   p?
						   printf("Found with"),print(p),printf("\n");
						   printf("Not found\n");
					   break;
				   }
			case 1:{//删除，陈工率<=33.3%
						printf("Removeing");
						print(e);printf("...\n");
						avl.remove(e)?printf("Done\n"),print(avl):printf("No exit\n");
						break;
				   }
			default:{//插入，成功率<=33.3%
						printf("Inserting");print(e);printf("...\n");
						BinNodePosi(T) p=avl.insert(e);
						if(p->data!=e){print(p->data);printf("<>");print(e);printf("\n");
							printf("Done with"),print(p),printf("\n"),print(avl);
							break;
						}
					}
		}
		while(avl.size()>0){
			T e=dice((T)n*3);//[0,3n)范围内的e
			printf("Removing ");print(e);printf("...\n");
			avl.remove(e)?printf("Done\n"),print(avl):printf("Not exit\n");
		}
		//测试主入口
		int main(int argc,char* argv[]){
			if(2>argc){printf("Usage:%s<size of test>\a\a\n",argv[0]);return 1;}
			srand((unsigned int ) time(NULL));
			testAVL<int>(atoi(argv[1]));/元素类型可以在这里任意选择
				return 0;
		}



