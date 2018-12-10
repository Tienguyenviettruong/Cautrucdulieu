#include<iostream>
using namespace std;
typedef int item;
typedef struct Node{
  item data;
  Node *Left,*Right;
};
typedef struct List{
  Node *Head;
  Node *Tail;
};
Void CreatList(List &alist){
  alist.Head = alist.Tail = NULL;
}
Node *q(item a){
  Node*q = new Node;
  q->data = a;
  q->Left = NULL;
  q->Right = NULL;
}
void AddHead(List &alist, Node* q)
{
  if(alist.Head){
    q->Right =  alist.Head;
    alist.Head->Left = q;
    alist.Head = q;
  }
  else{alist.Head= alist.Tail=q}
}
Void AddTail(List &alist, Node* q){
  if(alist.Head)
  {
    alist.Tail->Right = q;
    q->Left = alist.Tail;
    alist.Tail = q;
  }
}
void AddBefore(List &alist, Node*q, Node *B)
{
  if(B)
  {
    q->Right = B;
    q->Left = B->Left;
    if(alist.Head==B)
    {
      alist.Head=B;
    }
    if(alist.Head!=B)
    {
      B->Left->Right = q;
    }
  }
  else
    AddTail(alist,q);
}
void Addafter(List &alist, Node*q, Node *A){
  if(A){
    q->Left= A;
    q->Right =A->Right;
    A->Right = q;
    if(alist.Tail== A) alist.Tail = A
    if(alist.Tail!=A)
      A->Right->Left = q;
  }else AddHead(list,q);
}
// Tìm phần tử
Node* Find(List &alist, int p){
  Node *i = alist.Head;
  while (i && i->data != p)
    i=i->Right;
  return i;
}
// Xóa phần tử
void RemoveHead(List &alist)
{
  if(alist.Head == alist.Tail){
    delete alist.Head;
    alist.Head = alist.Tail = NULL;
  }
  else{
    Node *temp = alist.Head;
    alist.Head->Right->Left = NULL;
    alist.Head = alist.Head->Right;
    delete temp;
  }
}
void RemoveTail(List &alist){
  if(alist.Head == alist.Tail){
    delete alist.Head;
    alist.Head = alist.Tail = NULL;
  }
  else{
    Node *temp = alist.Tail;
    alist.Tail->Left->Right = NULL;
    alist.Tail = alist.Tail->Left;
    delete temp;
  }
}
void RemoveBefore(List &alist, Node *q){
  if(alist.Head!= q){
    Node *temp = q->Left;
    q->Left->Right = q;
    q->Left = q->Left->Left;
    delete temp;
  }
}
void RemoveAfter(List &alist, Node *q){
  if(alist.Tail!= q){
    Node *temp = q->Right;
    q->Right->Left = q;
    q->Right = q->Right->Right;
    delete temp;
  }
}
int main()
{
  return 0;
}
