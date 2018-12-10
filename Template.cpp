#include <iostream>
using namespace std;
template<class T>
const int maxItem = 100;
class list
{
private:
	item_type item[maxItem];
	int size;
public:
	
	list();
	void push_front(T newItem);//chen dau
	void pop_front(); //xoa dau
	void push_back(T newItem);//chen cuoi
	void pop_back();//xoa cuoi
	void insert(int index, T newItem);//chen vt bat ky
	void remove(int index);//xoa vi tri bat ky
	bool isEmpty(); //kiem tra xem list co rong khong
	bool isFull();//kiem tra list co bi day khong
	T retrieve(int index);//truy xuat pt tai vi tri
	int getSize();
	
	/////////////////////////// su dung isFull, isEmpty	
};
template<class T>
list<T>::list() { size = 0; }
template<class T>
void list<T>::push_front(T newItem)
{
  if(!isFull()) //(size < maxItem)
  {
    for (int i = size; i > 0; i--)
      item[i] = item[i - 1];
    item[0] = newItem;
    size++;
  }
  else
    cout << "Danh sach day" << endl;
}
template<class T>
void list<T>::pop_front()
{
  if (!isEmpty()) //(size > 0)
  {
    for (int i = 1; i < size; i++)
      item[i - 1] = item[i];
    size--;
  }
  else
    cout << "Danh sach rong" << endl;
}
template<class T>
void list<T>::push_back(T newItem)
{
  if (!isFull()) //(size < maxItem)
  {
    item[size] = newItem;
    size++;
  }
  else
    cout << "Danh sach day" << endl;
}
template<class T>
void list<T>::pop_back()
{
  if (!isEmpty())// (size >0)
    size--;
  else
    cout << "Danh sach rong" << endl;
}
void list<T>::printList()
{
  for (int i = 0; i < size; i++)
    cout << item[i] << " ";
  cout << endl;
}
template<class T>
void list<T>::insert(int index, T newItem)
{
  if (index < 0 || index > size)
    cout << "Vi tri khong hop le" << endl;
  else
  {
    for (int i = size; i >= index; i--)
      item[i] = item[i - 1];
    item[index - 1] = newItem;
    size++;
  }
}
template<class T>
void list<T>::remove(int index)
{
  if (index < 0 || index > size)
    cout << "Vi tri khong hop le" << endl;
  else
  {
    if(!isEmpty()) //(size > 0)
    {
      for (int i = index; i < size; i++)
        item[i - 1] = item[i];
      size--;
    }
    else
      cout << "Danh sach rong" << endl;
  }
}
template<class T>
bool list<T>::isEmpty() //kiem tra xem list co rong khong
{
  if (size == 0)
    return true;
  else
    return false;
}
template<class T>
bool list<T>::isFull()//kiem tra list co bi day khong
{
  if (size == maxItem)
    return true;
  else
    return false;
}
template<class T>
T list<T>::retrieve(int index)//truy xuat pt tai vi tri
{
  if (index < 0 || index > size)
    cout << "Vi tri khong hop le" << endl;
  else
    return item[index - 1];
}
template<class T>
int list<T>::getSize() { return size; }
int main()
{
	list alist;
	/*alist.push_back(3);
	alist.push_front(56);
	alist.push_front(7);
	alist.push_front(9);
	alist.printList();

	alist.insert(2,6);
	alist.printList();*/
	//Nhap list
	T gt;
	int n;
	cout << "Ban nhap bao nhieu phan tu:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Moi nhap pt thu " << i + 1 << ":";
		cin >> gt;
		alist.push_back(gt);
	}
	cout << "List ban vua nhap la:" << endl;
	alist.printList();
	//tinh tong max, min
	T tong = 0, max, min;
	tong = max = min = alist.retrieve(1);
	for (int i = 2; i <= alist.getSize(); i++)
	{
		if (alist.retrieve(i) < min)
			min = alist.retrieve(i);
		if (alist.retrieve(i) > max)
			max = alist.retrieve(i);
		tong = tong + alist.retrieve(i);
	}
	cout << "Tong =" << tong<<endl;
	cout << "Max =" << max << endl;
	cout << "Min =" << min << endl;
	return 0;
	system("pause");
	
}
