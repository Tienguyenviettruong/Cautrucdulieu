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
    list(){head = NULL; size = 0}
   
};
