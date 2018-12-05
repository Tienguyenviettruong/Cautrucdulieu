#include<iostream>
using namespace std;
typedef int item_type;
const int maxItem=100;
class list{
private:
	item_type item[maxItem];
	int size;
public:
	list() {size =0;}// cau tu mac dinh
	void Nhap()
	{
		cin >> size;
		for(int i = 0; i < size; i++)
		{
			cin>>item[i];
		}
	}
	void push_front(item_type newItem)//chen vao mang vi tri dau
	{	
		for(int i = size; i > 0; i--){
			item[i]= item[i-1];
			item[0] = newItem;
			size++;
		}
		
	}
	void pop_front()
	{	if (size< maxItem)
		{for(int i = 1; i< size; i++)
			item[i-1]= item[i];
			size--;}
		
	}
	void push_back(item_type newItem){
			
		if(size < maxItem){
			item[size] = newItem;	
			size++;
		}
	}	

	void pop_back(){
		if(size < maxItem)
			size--;
	}
	void printList(){
		for(int i = 0; i < size; i++)
		{cout<<item[i]<<"";}
	}
	void insert(int index, item_type newItem)
	{	if(index<0 && index> size) 
			cout<<"loi"<<endl;
		else{
			for(int i = size; i>=index; i--)
				item[i]=item[i-1];
			item[index-1]=newItem;
			size++;
			
		}	}
	void remove(int index){
		if (size< maxItem)
		{for(int i = index; i< size; i++)
			item[i-1]= item[i];
			size--;}
	}
	bool isEmpty()
	{
		if(size == 0) return true; else return false;
	}
	item_type retrieve(int index){
		if (index< 0 && index> size)
			cout<<"vi tri ko hop le"<<endl;
		else
			return item[index-1];
	}
};
int main(){
	list alist;
	alist.Nhap();
	alist.push_back(3);
	alist.insert(2,6);
	alist.printList();
	return 0;
}
