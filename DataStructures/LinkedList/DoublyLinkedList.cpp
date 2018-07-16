#include<iostream>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}
class DoublyLinkedList{
    public: 
    Node *head,*tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void createNode(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void printList()
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}