#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}
class List{
    public: Node *head,*tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void createNode(int value){
        Node *temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
    }
    void printList()
    {
        Node *temp = head;
        if(head != NULL){
            do{
                cout<<temp->data;
                temp temp = temp->next;
            }while(temp != head);
        }
    }
}