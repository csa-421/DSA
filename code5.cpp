/* Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked list. compute and display- 
i. Set of students who like either vanilla or  butterscotch or both 
ii. Set of students who like  both vanilla and  butterscotch 
iii. Set of students who like  only vanilla not butterscotch 
iv. Set of students who like only butterscotch not vanilla 
v. Number of students who like neither vanilla nor butterscotch */
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
	node()
	{
		next = NULL;
	}
};
class LinkedList
{
	public:
	node *head, *temp, *q;
	LinkedList()
	{
		head = temp = q = NULL;
	}
	void insert(int data)
	{
		temp = new node;
		temp -> data = data;
		if(head == NULL)
			head = temp;
		else
		{
			q = head;
			while( q -> next != NULL )
			{
				q = q->next;
			}
			q -> next = temp;
		}
		temp = q = NULL;
	}
	void display()
	{
		if(head != NULL)
		{
			cout<<"\n----------LINKED LIST DATA---------\n\n";
			q = head;
			while(q != NULL)
			{
				cout<<"  <  "<<q->data<<" , "<<q->next<<"  > -->> ";
				q = q-> next;
			}
		}
		q = NULL;
	}
	int Search(int data)
	{
		if(head == NULL)
			return 0;
		q = head;
		while(q != NULL)
		{
			if(q->data == data)
				return 1;
			q = q-> next;
		}
		q = NULL;
		return 0;
	}
};
class icecream
{
	LinkedList tot, butterscotch, vanilla, l1, l2, l3, l4, l5;
	int ntot, nbutterscotch, nvanilla, rollno;
	public:
		icecream()
		{
			ntot = 0; 
			nbutterscotch = 0;
			nvanilla = 0;
		}
		void accept()
		{
			cout<<"\nEnter the total number of students in the class:-> ";
			cin>>ntot;
			cout<<"\nEnter their roll numbers:-> \n";
			for(int i = 0; i<ntot; i++)
			{
				cin>>rollno;
				tot.insert(rollno);
			}
			tot.display();

			cout<<"\nEnter the total number of students in the class who like buterscotch icecream:-> ";
			cin>>nbutterscotch;
			cout<<"\nEnter their roll numbers:-> \n";
			for(int i = 0; i<nbutterscotch; i++)
			{
				cin>>rollno;
				butterscotch.insert(rollno);
			}
			butterscotch.display();

			cout<<"\nEnter the total number of students in the class who like vanilla icecream:-> ";
			cin>>nvanilla;
			cout<<"\nEnter their roll numbers:-> \n";
			for(int i = 0; i<nvanilla; i++)
			{
				cin>>rollno;
				vanilla.insert(rollno);
			}
			vanilla.display();
		}
		void f_1()
		{
			/*Set of students who like either vanilla or  butterscotch or both*/
			cout<<"\nSet of students who like either vanilla or  butterscotch or both:-> ";
			node *temp1;
			temp1 = tot.head;
			while(temp1 != NULL)
			{
				if(butterscotch.Search(temp1 -> data) || vanilla.Search(temp1 -> data))
				{
					cout<<temp1->data<<"  ";
				}
				temp1 = temp1 -> next;
			}			
		}
		void f_2()
		{
			/*Set of students who like  both vanilla and  butterscotch */
			cout<<"\nSet of students who like both vanilla and  butterscotch :-> ";
			node *temp1;
			temp1 = tot.head;
			while(temp1 != NULL)
			{
				if(butterscotch.Search(temp1 -> data) && vanilla.Search(temp1 -> data))
				{
					cout<<temp1->data<<"  ";
				}
				temp1 = temp1 -> next;
			}	
		}
		void f_3()
		{
			/* Set of students who like  only vanilla not butterscotch */
			cout<<"\n Set of students who like  only vanilla not butterscotch :-> ";
			node *temp1;
			temp1 = tot.head;
			while(temp1 != NULL)
			{
				if(!butterscotch.Search(temp1 -> data) && vanilla.Search(temp1 -> data))
				{
					cout<<temp1->data<<"  ";
				}
				temp1 = temp1 -> next;
			}	
		}
		void f_4()
		{
			/*Set of students who like only butterscotch not vanill */
			cout<<"\nSet of students who like only butterscotch not vanilla :-> ";
			node *temp1;
			temp1 = tot.head;
			while(temp1 != NULL)
			{
				if(butterscotch.Search(temp1 -> data) && !vanilla.Search(temp1 -> data))
				{
					cout<<temp1->data<<"  ";
				}
				temp1 = temp1 -> next;
			}	
		}
		void f_5()
		{
			int count = 0;
			/*Set of students who like only butterscotch not vanilla */
			cout<<"\nSet of students who like neither butterscotch nor vanilla :-> ";
			node *temp1;
			temp1 = tot.head;
			while(temp1 != NULL)
			{
				if(!butterscotch.Search(temp1 -> data) && !vanilla.Search(temp1 -> data))
				{
					cout<<temp1->data<<"  ";
					count ++;
				}
				temp1 = temp1 -> next;
			}
			cout<<"\nNumber of students who like neither butterscotch nor vanilla :-> "<<count;
		}
};
int main()
{
	icecream i1;
	i1.accept();
	i1.f_1();
	i1.f_2();
	i1.f_3();
	i1.f_4();
	i1.f_5();
	return 0;	
}
/*
Output:
Enter the total number of students in the class:-> 10

Enter their roll numbers:->
1
2
3
4
5
6
7
8
9
10

----------LINKED LIST DATA---------

  <  1 , 0x181500  > -->>   <  2 , 0x181520  > -->>   <  3 , 0x181cc0  > -->>   <  4 , 0x181ce0  > -->>   <  5 , 0x181d00  > -->>   <  6 , 0x181d20  > -->>   <  7 , 0x181d40  > -->>   <  8 , 0x181d60  > -->>   <  9 , 0x181d80  > -->>   <  10 , 0  > -->>
Enter the total number of students in the class who like buterscotch icecream:-> 4

Enter their roll numbers:->
1
2
3
4

----------LINKED LIST DATA---------

  <  1 , 0x181dc0  > -->>   <  2 , 0x181de0  > -->>   <  3 , 0x181e00  > -->>   <  4 , 0  > -->>
Enter the total number of students in the class who like vanilla icecream:-> 4

Enter their roll numbers:->
4
5
6
7

----------LINKED LIST DATA---------

  <  4 , 0x186d60  > -->>   <  5 , 0x186e00  > -->>   <  6 , 0x186e40  > -->>   <  7 , 0  > -->>
Set of students who like either vanilla or  butterscotch or both:-> 1  2  3  4  5  6  7
Set of students who like both vanilla and  butterscotch :-> 4
 Set of students who like  only vanilla not butterscotch :-> 5  6  7
Set of students who like only butterscotch not vanilla :-> 1  2  3
Set of students who like neither butterscotch nor vanilla :-> 8  9  10
Number of students who like neither butterscotch nor vanilla :-> 3*/