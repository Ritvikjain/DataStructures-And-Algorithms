#include <iostream>
using namespace std;
struct Node{
	struct Node* left;
	int data;
	struct Node* right;
};
struct Node* createNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct Node* insert(struct Node* root,int data)
{
	if(root==NULL)
	{
		return createNode(data);
	}
	if(root->data>data)
	{
		root->left = insert(root->left,data);
	}
	else
	{
		root->right = insert(root->right,data);
	}
	return root;
}
void inorder(struct Node* root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(struct Node* root)
{
	if(root==NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void preorder(struct Node* root)
{
	if(root==NULL)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	int n;
	cin>>n;
	struct Node* root = NULL;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		root = insert(root,temp);
	}
	cout<<"Inorder Traversal :"<<endl;
	inorder(root);
	cout<<endl<<"Postorder Traversal :"<<endl;
	postorder(root);
	cout<<endl<<"Preorder Traversal :"<<endl;
	preorder(root);
}
