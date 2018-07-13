#include<iostream>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}
class List{
    public: Node *head,*tail;
    List(){
        head = NULL;
        tail = NULL;
    }
    void createNode(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        if(head = NULL)
        {
            head = temp;
            temp->next = head;
            tail = temp;
            temp->prev = head;
        }
        else{
            tail->next = temp;
            temp->next = head;
            temp->prev = tail;
            head->prev = temp;
            tail = temp;
        }
    }
    void dispList()
    {
        Node *temp = head;
        if(head!=NULL){
            do{
                cout<<temp->data;
                temp = temp->next;
            }
            while(temp!=head);
        }
    }
    void revListPrint(){
        Node *temp = tail;
        if(head!=NULL){
            do{
                cout<<temp->data;
                temp = temp->prev;
            }
            while(temp!=tail);
        }
    }
}