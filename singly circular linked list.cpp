//circular singly linked list

#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
	node *head=NULL;
	void insertbeg(int val)
	{
	  	node *newnode=new node();
	  	newnode->data=val;
	  	newnode->next=NULL;
	  	if(head==NULL)
	  	  head=newnode;
	  	else
	  	{
	  	  newnode->next=head;
	  	  head=newnode;
		  }	  	
   }
   void insertend(int val)
   {
   	node *newnode=new node();
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	{
	  	  head=newnode;
	  	  return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    { temp=temp->next;
	}
	
	temp->next=newnode;
	
   }
   void deletebeg()
   {
   	node *temp;
   	if(head==NULL)
   	{cout<<" the list is empty. u can't delete "<<endl;
   	 return;
	 }
   	temp=head;
   	head=head->next;
   	cout<<"the deleted item is "<<temp->data<<endl;
   	delete(temp);
   }
   void deleteend()
   {
   	node *prev=NULL, *temp=head;
   	while(temp->next!=NULL)
   	{ prev=temp;
   	  temp=temp->next;
   }
   prev->next=NULL;
   cout<<"the deleted item is "<<temp->data<<endl;
   delete(temp);
   }
   
   void display()
   {
   	node *temp=head;
   	while(temp!=NULL)
   	{
   		cout<<temp->data<<" ";
   		temp=temp->next;
	   }
   }
   void insertmiddle(int val)
   {int n;
   	node *newnode=new node();
	newnode->data=val;
	newnode->next=NULL;
	if(head==NULL)
	{
	  	  head=newnode;
	  	  return;
    }
    cout<<"enter the number of nodes after which you want to insert this ";
    cin >>n;
    node *temp=head;
    int count=1;
    while(count<n && temp->next!=NULL)
    {
      temp=temp->next;
      count++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
   }
   void deletemiddle()
   {int delval;
   	 node *prev=NULL,*temp=head;
   	 cout<<"enter the node value that u want to delete ";
   	 cin>>delval;
   	 while(temp->data!=delval&&temp->next!=NULL)
   	 {
   	 	prev=temp;
   	 	temp=temp->next;
	 }
	 if(temp->data!=delval)
	{cout<<"there is no such node in the list";
	  return;
	}
	 prev->next=temp->next;
	 cout<<"deleted item is "<<temp->data<<endl;
	 delete(temp);
   }
};
int main()
{
	int choice,val;
	node obj;
	do
	{
	
	cout<<"enter ur choice 1-insert in the beg   2-insert at the end    3- insert in middle  4-deletebeg   5- delete end    6-delete middle    7-display   8-exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"enter the value u want to insert ";
		        cin>>val;
		        obj.insertbeg(val);
		        break;
	    case 2: cout<<"enter the value u want to insert ";
		        cin>>val;
		        obj.insertend(val);
		        break;
		case 3: cout<<"enter the value u want to insert ";
		        cin>>val;
		        obj.insertmiddle(val);
		        break;
	    	    
	    case 4:obj.deletebeg();
	           break;
	    case 5:obj.deleteend();
	           break;
	    case 6: obj.deletemiddle();
	            break;
	    case 7: obj.display();
	            break;
	    
	}
  }while(choice!=8);
}

