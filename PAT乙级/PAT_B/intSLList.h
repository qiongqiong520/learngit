 ///
 /// @file    intSLList.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-18 14:53:03
 ///
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode{
	public:
		IntSLLNode{
			next=0;
		}
		IntSLLNode(int el,IntSLLNode *ptr =0){
			info =el;
			next =ptr;
		}
		int info;
		IntSLLNode*next;
}

class IntSLList{
	public:
		IntSLList(){
			head=tail=0;
		}
		~IntSLList();
		int isEmpty(){
			return head==0;
		}
		void addToHead(int);
		void addToTail(int);
		void deleteFromHead();
		void deleteFromTail();
		void deleteNode(int);
		bool isInList(int)const;
	private:
		IntSLLNode *head,*tail;
};


		void delete

