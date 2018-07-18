#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *left,*right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//PostOrder Traversal
void printPostorder(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }
     
    printPostorder(node->left);
    printPostorder(node->right);

    cout<<node->data<<" ";
}

//InOrder Traversal
void printInorder(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }
     
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

//PreOrder Traversal
void printPreorder(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }

    cout<<node->data<<" ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Postorder Traversal : ";
    printPostorder(root);

    cout<<endl<<"Inorder Traversal : ";
    printInorder(root);

    cout<<endl<<"Preorder Traversal : ";
    printPreorder(root);
}