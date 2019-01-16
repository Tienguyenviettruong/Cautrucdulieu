#ifndef queue_h
#define queue_h

template <class T>

class Queue
{
private:
	QNode<T> *bot;
public:
	Queue()
	{
		bot = 0;
	}
	void EnQueue(T value)
	{
		QNode<T> *n = new QNode<T>;
		n->data = value;
		n->next = 0;
		if (bot == 0)
			bot = n;
		else
		{
			QNode<T> *q = bot;
			while (q->next != 0)
				q = q->next;
			q->next = n;
		}
	}
	T DeQueue()
	{
		T t = bot->data;
		QNode<T> *q = bot;
		bot = bot->next;
		delete q;
		return t;
	}
	bool IsEmpty() const
	{
		return bot == 0;
	}
};

#endif