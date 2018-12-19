#include<iostream>
#include<string>
using namespace std;
typedef char item_type;
const int maxItem = 100;
class stack
{
private:
	item_type item[maxItem];
	int size;
public:
	stack(){
		size = 0;
	}
	bool isEmpty()const{
		if (size == 0)
			return true;

		else
			return false;
	}
	void push(item_type newItem)
	{
		if (size >= maxItem)
			cout << "Full stack" << endl;
		else
		{
			item[size] = newItem;
			size++;
		}
	}
	void pop(){
		size--;
	}
	void pop(item_type & stacksize){
		stacksize = item[size - 1];
		size--;
	}
	item_type getStacksize(){
		return item[size-1];
	}
	/*int Uu_Tien(char s)
	{
		if (s == '+' || s == '-')
			return 1;
		if (s == '*' || s == ' / ' || s == '%')
			return 2;
		return 0;
	}*/



};
//int main()
//{
//	stack s;
//	string ch = "(10-(3*((14-2)/(2+4))))", kq;
//	char a, x;
//	int i = 0, j = 0;
//	int dodai = ch.length();//l?y d? dài xâu trung t? 
//	//gán d? dài xâu kq = xâu trung t?
//	kq = new char[dodai];
//	cout << "Bat dau" << endl;
//	//ch?y t? d?u d?n cu?i bi?u th?c trung t?
//	// ki?m tra t?ng ký t? d?c du?c là gì 
//	while (i < dodai)
//	{
//		x = ch[i];
//		if (x == '(') //n?u là m? ngo?c dua vào stack
//			s.push(x);
//		else if ((x == '+') || (x == '-') || (x == '*') || (x == '/'))
//		{//n?u là toán t? dua vào stack
//			s.push(x);
//		}
//		else if (x == ')')
//		{//n?u là dóng ngo?c: l?y t? stack cho d?n khi g?p (
//			a = s.getStacksize(); //s.getStacksize(a);
//			cout << "a=" << a << endl;
//			while ((a != '(') && (!s.isEmpty()))
//			{
//				kq[j] = a;
//				j++;
//				s.pop();
//				a = s.getStacksize(); //s.getStacksize(a);
//			}
//			s.pop(); //bo dau mo ngoac
//		}
//		else //n?u là toán h?ng -> dua vào bi?u th?c kq)
//		{
//			kq[j] = x;
//			j++;
//		}
//		i++;
//	}
//	while (!s.isEmpty())
//	{ //l?y n?t các toán t? trong stack sang bi?u th?c kq
//		s.pop(x);//x= s.pop();
//		kq[j] = x;
//		j++;
//	}
//	cout << "Ket qua la" << endl;
//	kq[j] = 0; //de loai bo ky tu thua
//	dodai = kq.length(); //strlen(kq);
//	//cout << "kq=" << kq << endl;
//	for (i = 0; i < j; i++)
//		cout << kq[i];
//	cout << endl;
//	system("pause");
//	return 0;
//}
//}
int main()
{
	stack s;
	//s.push(7);
	//cout << s.getStacksize() << endl;
	// can bang ngoac
	//bool kiemTraDau(string str, stack s)
	/*string  str = "(a+b)+(c+d)";*/
	//cin >> str;

	//for (int i = 0; i <str.length(); i++)
	//{
	//	if (str[i] == '(')
	//		s.push('(');
	//	if (str[i] == ')')
	//		s.pop();
	//}
	//if (s.isEmpty())
	//	cout << "sau can bang" << endl;
	//else
	//	cout << "sau khong can bang" << endl;
	//bai2  chuyển biểu thức trung tố sang hậu tố*******************************************
	string ch = "a-(b+c*d)/e", kq;
	char a, x;
	int i = 0,j = 0;
	int DoDai = ch.length();//lây sđộ dài sâu trung tố
	//gán độ dài xâu kq= xâu trung tố
	kq = new char[DoDai];
	cout << "bat dau" << endl;
// chạy từ đầu dến cuối biểu thcws trung tố
	// kiểm tra từng ký tự đọc đc là gì 
	while (i < DoDai)
	{
		x = ch[i];
		if (x == '(')// nếu là mở ngoạc thì đưa vào stack
			s.push(x);
		else if (x == '+' || x == '-' || x == '*' || x == ' / ')// nếu là toán tử đưa vào stack
		{
			s.push(x);
		}
		else if (x == ')')
			//nếu là dấu đóng ngoặc ; lấy từ stack lcho đến khi gặp (
		{
			a = s.getStacksize(); // 
			//cout << "a=" << a << endl;
			while ((a != '(') && (!s.isEmpty()))
			{
				kq[j] = a; j++;
				s.pop();
				a = s.getStacksize();// s.getStacksize(a)
			}
			s.pop();// xóa dấu mở ngoạc
		}
		else // nếu là toán hạng-> đưa vào biểu thức kết quả
		{
			kq[j] = x;
			j++;
		}
		i++;
	}
	while (!s.isEmpty())
	{//lấy nốt các toán tử trong stack sang biểu thức kết quả
		s.pop(x);
		kq[j]= x;
		//cout << "gg" << kq[j] << endl;
		j++;
	}

	cout << "trươc khi hien thi ket qua" << endl;
	kq[j] = 0;// de loại  bo ky tư thưa
	DoDai = kq.length();
	//cout << "kq" << kq << endl;
	
	for (int k = 0; k < j; k++)
		cout << kq[k];
	cout << endl;
	// tinh toan
	a[100] = "52|7*8+";
	int tong = 0;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i]>='0' && a[i]<='9')
		{	
			tong = tong*10 + (a[i] - '0');
		}
		else
		{
			s.Push(tong);
			tong = 0;
			if (s.Get())
			{ 
				int s2 = s.Pop();
				int s1 = s.Pop();
				if (a[i] == '+')
					s.Push(s1+s2);
				if (a[i] == '-')
					s.Push(s1-s2);
				if (a[i] == '*')
					s.Push(s1*s2);
				if (a[i] == '/')
					s.Push(s1/s2);
			}
		}
	}
	cout<<s.Pop()<<endl;
	system("pause");
	return 0;
}
