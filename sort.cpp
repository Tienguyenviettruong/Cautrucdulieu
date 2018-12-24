#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void nhap();
void selectionSort(int a[], int n);
void bubbleSort(int a[], int n);
void random(int a[], int n);
void InsertSort(int arr[], int n);

int main()
{
	clock_t begin = clock();
	//nhap();
	int n;
	int a[n];
	cin>>n;
	ifstream file;
	file.open("data.txt");
	random(a,n);
	file.close();
	// print array
	/*for(int  i =0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}*/
	//selectionSort(a,n);
	bubbleSort(a,n);
	//print result
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	clock_t end = clock();
	cout<<float(end-begin)/CLOCKS_PER_SEC<<endl;
	return 0;
}
void nhap()
{
	int n;
	int x;
	cout<<"Moi ban nhap so phan tu: ";
	cin>>n;
	ofstream file("data.txt");
	file << n<<endl;
	for(int i = 0;i<n;i++)
	{
		cin >> x;
		file << x<<endl;
	}
	file.close();
}
void selectionSort(int a[], int n)
{
	int i, j, min_index,temp;
	for( i = 0;i<n-1;i++)
	{
		min_index = a[i];
		for( j = i +1;j<n;j++)
		{
			if(a[j]<min_index)
			{
				min_index = a[j];
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}*/
void bubbleSort(int a[], int n)
{
	for(int  i = 0;i<n-1;i++)
	{
		for(int j = 0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	/*for (int i = 0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}*/
}
void random(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		a[i] = rand();
	}
}
void InsertSort(int arr[], int n)
{
	int temp, j;
	for (int i = 1; i<n; i++)
	{
		j = i - 1;
		temp = arr[i];
		while (j >= 0 && t<arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
