#include<iostream>
using namespace std;
typedef int item_type;
class stack{
private:
	struct node{
		item_type item;
		node *next
	};
	node *top;
	int size;
public:
	stack(){ top = NULL; size = 0; }
	void push(item_type newItem){
		node *q = new node();
		q->item = newIten;
		node *cur = top;
		top = q;
		q->next = cur;
		size++;
	}
	void pop(){
		node *del = top;
		top=top->next;
		del->next = NULL;
		delete del;
		size--;
	}
	void pop(item_type &popItem){
		node *del = top;
		top = top->next;
		popItem = del->item;
		del->next = NULL;
		delete del;
		size--;
	}
	item_type gettop()// truy xuaats gia tri tai dinh stack
};
