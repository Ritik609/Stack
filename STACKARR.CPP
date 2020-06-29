//Wap to implement stack using array
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
# define max 50

 //class Definition
 class stack
  {
    public:
    int data[max];
    int top;
    stack()
     {
       top=-1;
     }

    //Function Definition for push operation
    void push()
     {
       int x;
       cout<<"\n\t\tEnter the data :-";
       cin>>x;
       if(top==max-1)
	{
	 cout<<"\n\tstack Overflow";

	}
       else
	{  top++;
	  data[top]=x;
	}
      cout<<"\n\t\tData Added Successfully";
    }
  void pop()
   {
     if(top==-1)
      {
       cout<<"\n\t\tStack Underflow";

      }
     else
      {
	    int x=data[top];
	    top--;
       cout<<"\n\t\tElement Deleted successfully";
       cout<<"\n\t\tDeleted Element is:-"<<x;
      }
   }

 //Function Definition for traversal
 void traversal()
  {
    if(top==-1)
     {
      cout<<"\n\t\tList is Empty";
     }
    else
     {

      for(int i=top;i>=0;i--)

	cout<<"\n\t\tElements in Stack are :-- "<<data[i];

     }
  }
 };

 //Main Function
 void main()
  {
    stack ob;         //Object Declaration
    int ch;
    do
     {
       cout<<"\n\t\t\t******************STACK*****************";
       cout<<"\n\t\t1.Push";
       cout<<"\n\t\t2.Pop";
       cout<<"\n\t\t3.Traversal";
       cout<<"\n\t\t4.Exit";
       cout<<"\n\t\tEnter your choice :-";
       cin>>ch;
       switch(ch)
	{
	  case 1:clrscr();
		 ob.push();
		 getch();
		 clrscr();
		 break;

	  case 2:clrscr();
		 ob.pop();
		 getch();
		 clrscr();
		 break;

	  case 3:clrscr();
		 ob.traversal();
		 getch();
		 clrscr();
		 break;

	  case 4:clrscr();
		 exit(1);
		 break;

	  default:clrscr();
		  cout<<"\n\t\tInvalid Choice";
		  getch();
		  clrscr();
		  break;
	}
     }while(ch!=4);
  getch();
 }