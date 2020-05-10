/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue.*/

#include<iostream>
#define MAX 10
using namespace std;

class Queue
{
	int front, rear, data[MAX];
	public:
	Queue()
	{
		front = rear = -1;
	}
	int isFull()
	{
		return rear == ( MAX - 1 )? 1 : 0;
	}
	int isEmpty()
	{
		return rear == - 1 ? 1 : 0;
	}

	void enqueue(int data)
	{
		if(isFull())
		{
			cout<<"\nQueue is Full\n\n";
			return;
		}
		if(isEmpty())
			front++;
		this -> data[++rear] = data;
	}
	void dequeue()
	{
		if(isEmpty())
			cout<<"\nQueue is Empty. \n";
		else
		{
			cout<<"\n"<<data[front++]<<endl;
			if(front > rear)
				front = rear = -1;
		}
	}
	void display()
	{
		cout<<"\n\nQUEUE CONTENTS:-> \n";
		if(isEmpty())
			cout<<"\nQUEUE IS EMPTY. ";
		else
		{
			for(int i = front; i<=rear; i++)
			{
				cout<<data[i]<<endl;
			}
		}
	}
	
};
int main()
{
	Queue q1;
	int data, choice;
	while(1)
	{
		cout<<"\nMENU:\n1. Enqueue\n2. Dequeue\n3. Display\n4. EXIT\n:-> ";
		cin>>choice;
		switch(choice)	
		{
			case 1:
				cout<<"\nEnter data to insert into the queue:-> ";
				cin>>data;
				q1.enqueue(data);
				break;
			case 2:
				q1.dequeue();
				break;
			case 3:
				q1.display();
				break;
			case 4: return 0;
		}
	}
		return 0;
}
/*
OUTPUT:

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 3


QUEUE CONTENTS:->

QUEUE IS EMPTY.
MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 1

Enter data to insert into the queue:-> 12

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 2

12

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 2

Queue is Empty.

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 1

Enter data to insert into the queue:-> 12

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 1

Enter data to insert into the queue:-> 13

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 1

Enter data to insert into the queue:-> 14

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 1

Enter data to insert into the queue:-> 15

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 3


QUEUE CONTENTS:->
12
13
14
15

MENU:
1. Enqueue
2. Dequeue
3. Display
4. EXIT
:-> 4
*/