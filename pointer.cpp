// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include<iostream>
using namespace std;
typedef int item_type;
class list{
private:
	struct node{
		item_type item;
		node *next;
	};
	node *head;
	int size;
public:
	list(){ head = NULL; size = 0; }
	node *find(int index){
		if (index < 0 || index > size)
			cout << "Vị trí không thỏa mãn";
		else{
			node *cur = head;
			for (int i = 1; i < index; i++){
				cur = cur->next;
				return cur;
			}
		}
	}
	void pushFront(item_type newItem){
		node *NewNode;
		NewNode = new node();
		NewNode->item = newItem;
		node *cur = head;
		head = NewNode;
		NewNode->next = cur;
		size++;
	}
	void popFront(){
		node *cur = head;
		head = head->next;
		cur->next = NULL;
		delete cur;
		size--;
	}
	void pushBack( item_type newItem){
		node *NewNode;
		NewNode = new node();
		NewNode->item = newItem;
		node *cur = find(size);
		cur->next = NewNode;
		NewNode->next = NULL;
		size++;
	}
	void popBack(){
		node *cur = find(size-1);
		node *del = cur->next;
		cur->next = NULL;
		delete del;
		size--;
	}
	void print(){
		node *cur = head;
		for (int i = 1; i <= size; i++){
			cout << cur->item << "";
			cur = cur->next;
		}
	}
		void Insert(item_type newItem, int index){
		node *NewNode = new node();
		NewNode->item = newItem;
		node* pre = find(index - 1);
		node* cur = pre->next;
		pre->next = NewNode;
		NewNode->next = cur;
		size++;
	}
	void Remove(int index){
		node *pre = find(index - 1);
		node*del = pre->next;
		node*cur = del->next;
		pre->next = cur;
		del->next = NULL;
		size--;
	}
};


int main()
{
	list alist;
	alist.pushBack(12);
	alist.print();
	return 0;
}

