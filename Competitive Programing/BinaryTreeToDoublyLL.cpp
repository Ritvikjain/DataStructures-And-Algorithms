#include<bits/stdc++.h>
using namespace std;
struct node{
	node* left;
	int data;
	node* right;
};
void convertBinaryToDoublyLL(node * p,node * head){
	if(p == NULL)
	{
		return;
	}
	static node* prev = NULL;
	convertBinaryToDoublyLL(p->left,head);
	if(prev == NULL)
	{
		head = p;
	}else{
		prev->right = p;
		p->left = prev;
	}
	prev = p;
	convertBinaryToDoublyLL(p->right,head);
}
int main()
{
	return 0;
}
