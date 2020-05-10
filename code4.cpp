/* In Second year Computer Engineering class of M students, set A of students play cricket and set B of students play badminton. Write C/C++ program to find and display- 
i. Set of students who play either cricket or  badminton or both 
ii. Set of students who play both cricket and badminton  
iii. Set of students who play only cricket  
iv. Set of students who play only badminton  
v. Number of students who play neither cricket nor badminton      
(Note- While realizing the set duplicate entries are to avoided) */
#include<iostream>
using namespace std;
class CompEngg
{	
	int tot[100], ntot, bad[100], nbad, crick[100], ncrick;
	public:
		void accept()
		{
			cout<<"\nEnter the total number of students in the class:-> ";
			cin>>ntot;
			cout<<"\nEnter the roll numbers of all the students:-> ";
			for(int i =0; i<ntot; i++)
			{
				cin >> tot[i];
			}
			cout<<"\nEnter the total number of students playing badminton:-> ";
			cin>>nbad;
			cout<<"\nEnter the roll numbers of all the students who play badminton :-> ";
			for(int i =0; i<nbad; i++)
			{
				cin >> bad[i];
			}
			cout<<"\nEnter the total number of students playing cricket:-> ";
			cin>>ncrick;
			cout<<"\nEnter the roll numbers of all the students who play cricket :-> ";
			for(int i =0; i<ncrick; i++)
			{
				cin >> crick[i];
			}
		}
		int Search(int arr[], int narr, int key)
		{
			for(int i = 0; i<narr; i++)
			{
				if( key == arr[i])
				{
					return 1;
				}
			}
			return 0;
		} 
		void display()
		{
			cout<<"\nThere are "<<ntot<<" number of students in the class:-> ";
			cout<<"\nTheir roll numbers are:-> \n";
			for(int i =0; i<ntot; i++)
			{
				cout<<tot[i]<<endl;
			}

			cout<<"\nThere are "<<nbad<<" number of students in the class who play badminton:-> ";
			cout<<"\nTheir roll numbers are:-> \n";
			for(int i =0; i<nbad; i++)
			{
				cout<<bad[i]<<endl;
			}

			cout<<"\nThere are "<<ncrick<<" number of students in the class who play cricket:-> ";
			cout<<"\nTheir roll numbers are:-> \n";
			for(int i =0; i<ncrick; i++)
			{
				cout<<crick[i]<<endl;
			}
		}
		void f1()
		{
			/* Set of students who play either cricket or badminton or both. */
			cout<<"\nSet of students who play either cricket or badminton or both:-> \n";
			for(int i =0; i< ntot; i++)
			{
				if(Search(bad, nbad, tot[i]) || Search(crick, ncrick, tot[i]))
				{
					cout<<tot[i]<<endl;
				}
			}
		}
		void f2()
		{
			/*  Set of students who play both cricket and badminton */
			cout<<"\nSet of students who play both cricket and badminton :-> \n";
			for(int i =0; i< ntot; i++)
			{
				if(Search(bad, nbad, tot[i]) && Search(crick, ncrick, tot[i]))
				{
					cout<<tot[i]<<endl;
				}
			}
		}
		void f3()
		{
			/*Set of students who play only cricket */
			cout<<"\nSet of students who play only cricket:-> \n";
			for(int i =0; i< ntot; i++)
			{
				if(!Search(bad, nbad, tot[i]) && Search(crick, ncrick, tot[i]))
				{
					cout<<tot[i]<<endl;
				}
			}
		}
		void f4()
		{
			/*Set of students who play only badminton */
			cout<<"\nSet of students who play only badminton:-> \n";
			for(int i =0; i< ntot; i++)
			{
				if(Search(bad, nbad, tot[i]) && !Search(crick, ncrick, tot[i]))
				{
					cout<<tot[i]<<endl;
				}
			}
		}
		void f5()
		{
			/*Number of students who play neither cricket nor badminton  */
			cout<<"\nSet of students who play neither cricket nor badminton :-> \n";
			int count = 0;
			for(int i =0; i< ntot; i++)
			{
				if(!Search(bad, nbad, tot[i]) && !Search(crick, ncrick, tot[i]))
				{
					count ++;
					cout<<tot[i]<<endl;
				}
			}
			cout<<"\nNumber of students who play neither cricket nor badminton:-> \n";
			cout<<count;
		}
};
int main()
{
	CompEngg c1;
	c1.accept();
	c1.display();
	c1.f1();
	c1.f2();
	c1.f3();
	c1.f4();
	c1.f5();
	return 0;
}
/*
Output:
Enter the total number of students in the class:-> 9

Enter the roll numbers of all the students:-> 1
2
3
4
5
6
7
8
9

Enter the total number of students playing badminton:-> 4

Enter the roll numbers of all the students who play badminton :-> 1
2
3
4

Enter the total number of students playing cricket:-> 3

Enter the roll numbers of all the students who play cricket :-> 3
5
6

There are 9 number of students in the class:->
Their roll numbers are:->
1
2
3
4
5
6
7
8
9

There are 4 number of students in the class who play badminton:->
Their roll numbers are:->
1
2
3
4

There are 3 number of students in the class who play cricket:->
Their roll numbers are:->
3
5
6

Set of students who play either cricket or badminton or both:->
1
2
3
4
5
6

Set of students who play both cricket and badminton :->
3

Set of students who play only cricket:->
5
6

Set of students who play only badminton:->
1
2
4

Set of students who play neither cricket nor badminton :->
7
8
9

Number of students who play neither cricket nor badminton:->
3
*/