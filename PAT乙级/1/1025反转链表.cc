 ///
 /// @file    反转链表.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 16:29:35
 ///
 
#include <iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;
class Node{
	public:
		int addr;
		int val;
		int next;
};

void swapval(Node &rhs1,Node &rhs2)
{
	int temp =rhs1.val;
	rhs1.val = rhs2.val;
	rhs2.val = temp;

	temp =rhs1.addr;
	rhs2.addr=rhs1.addr;
	rhs1.addr=temp;

}//节点内容交换

int main(int argc,char* argv[])
{
	int init,n,k;
	while(cin>>init>>n>>k){
 		Node *hash =new Node[100000];
		Node *list = new Node[n];
		int isright = false;
		for(int i=0;i<n;i++)
		{
 		 	int address;
			cin>>address;
			int value;
			cin>>value;
			int next;
			cin>>next;
			hash[address].addr=address;
			hash[address].val = value;
			hash[address].next =next;
			if(address==init)isright =true;
		}
		if(!isright){
			printf("\n");return 0;
		}
		int address=init;
		int num=0;
		for(;num<n;num++)
		{
			 if(address<0)break;
			list[num].addr = address;
			list[num].val = hash[address].val;
			list[num].next = hash[address].next;
			address =hash[address].next;
		}
		for(int i=0;i+k-1<num;i+=k){
			for(int j=0;j<k/2;j++){
				swapval(list[i+j],list[i+k-1-j]);
			}
		}
		for(int i=0;i<num-1;i++){
			list[i].next=list[i+1].addr;
		}
		list[num-1].next=-1;
		for(int i=0;i<num;i++)
		{
		 	if(list[i].next<0)
		 		printf("%05d %d %d\n",list[i].addr,list[i].val,list[i].next);
			else
			 	printf("%05d %d %05d\n",list[i].addr,list[i].val,list[i].next);
		
		}
	}
	return 0;
}


