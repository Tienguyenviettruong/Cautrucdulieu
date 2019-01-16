#include "node.h"
#include "qnode.h"
#include "queue.h"
template <class T>
class Tree
{
private:
	Node<T> *root;
	void Print(Node<T> *root) const
	{
		if (root !=0)
		{
			Print(root->Left);
			cout<<root->data<<" ";
			Print(root->Right);
		}
	};
public:
	Tree()
	{
		root = 0;
	}
	void AddChild(T v)
	{
		Node<T> *n = new Node<T>;
        n->data = v;
        n->Left = 0;
        n->Right = 0;
        if (root == 0)
            root = n;
        else
		{
			Queue<Node<T> *> q;
            Node<T> *p = root;
            q.EnQueue(p);
            while (!q.IsEmpty())
            {
                Node<T> *t = q.DeQueue();
                if (t->Left == 0)
                {
                    t->Left = n;
                    break;
                }
                else if (t->Right == 0)
                {
                    t->Right = n;
                    break;
                }    
                else
                {
                    q.EnQueue(t->Left);
                    q.EnQueue(t->Right);
                }
            }
		}
	}

	void Add(T value1, T value2)
	{
		Queue<Node<T> *> q;
        Node<T> *p = root;
        q.EnQueue(p);
  		if (Search(value1))
        {
	  		while (!q.IsEmpty())
	        {
				Node<T> *t = q.DeQueue();
				{
					if (value1 != t->data)
					{
						if (t->Left == 0)
			                continue;
			            else if (t->Right == 0)
			            	continue;
			            else
			            {
			                q.EnQueue(t->Left);
			                q.EnQueue(t->Right);
			            }
					}
					else
			        {
						if (t->Left == 0)
						{
							if (t->Right == 0)
								t->Left->data = value2;
							break;
						}
						else
						{
							if (t->Right ==0)
								t->Right->data = value2;
							break;
						}
				    }
				}
			}
		}
	}

	bool Search(T v)
	{
		if (root->data == v)
			return true;
		Queue<Node<T> *> q;
        Node<T> *p = root;
        q.EnQueue(p);
        while (!q.IsEmpty())
        {
            Node<T> *t = q.DeQueue();
            if (t->data == v)
            	return true;
            if (t->Left == 0)
                continue;
            else if (t->Right == 0)
            	continue;
            else
            {
                q.EnQueue(t->Left);
                q.EnQueue(t->Right);
            }
            
        }
		return false;
	}

	T Max() const
	{
		T max = root->data;
		Queue<Node<T> *> q;
        Node<T> *p = root;
        q.EnQueue(p);
        while (!q.IsEmpty())
        {
            Node<T> *t = q.DeQueue();
            if (t->data > max)
            	max = t->data;
            if (t->Left == 0)
                continue;	
            else if (t->Right == 0)
            {
            	if (t->Left !=0)
            		q.EnQueue(t->Left);
            	else
            		continue;
            }
            else
            {
                q.EnQueue(t->Left);
                q.EnQueue(t->Right);
            }
        }
        return max;
	}	

	void PreOrder() const
	{
		Print(root);
		cout<<endl;
	}
};