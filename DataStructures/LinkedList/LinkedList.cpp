#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
class List
{
	public:
	Node *head,*tail;
	List()
	{
		head=NULL;
		tail=NULL;
	}
	void createNode(int value)
	{
		Node *temp=new Node;
		temp->data=value;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	void disp()
	{
		Node *temp=new Node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	void insertStart(int value)
	{
		Node *temp=new Node;
		temp->data=value;
		temp->next=head;
		head=temp;
	}
	void insertPosition(int pos,int value)
	{
		Node *pre=new Node;
		Node *cur=new Node;
		Node *temp=new Node;
		cur=head;
		temp->data=value;
		for(int i=1;i<pos;i++)
		{
			pre=cur;
			cur=cur->next;
		}
		pre->next=temp;
		temp->next=cur;
	}
	void deleteFirst()
	{
		Node *temp=new Node;
		temp=head;
		head=head->next;
		delete temp;
	}
	void deleteLast()
	{
		Node *cur=new Node;
		Node *pre=new Node;
		cur=head;
		while(cur->next!=NULL)
		{
			pre=cur;
			cur=cur->next;
		}
		pre->next=NULL;
		delete cur;
	}
	void deletePosition(int pos)
	{
		Node *cur=new Node;
		Node *pre=new Node;
		cur=head;
		for(int i=1;i<pos;i++)
		{
			pre=cur;
			cur=cur->next;
		}
		pre->next=cur->next;
		delete cur;
	}
};
