#include <iostream>
using namespace std;
#include "tree.h"

int main()
{
	Tree<int> T;
	T.AddChild(1);
	T.AddChild(2);
	T.AddChild(3);
	T.PreOrder();
	return 0;
}