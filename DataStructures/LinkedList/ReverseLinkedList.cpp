#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
struct Node* createNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node* insert(Node* head,int data)
{
    if(head == NULL)
    {
        return createNode(data);
    }
    struct Node* temp = createNode(data);
    struct Node* curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
Node* reverseLinkedList(Node* head)
{
    if(head == NULL)
        return head;
    struct Node* curr = head;
    struct Node* next = head->next;
    struct Node* prev = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void disp(Node* head)
{
    if(head == NULL)
        return;
    struct Node* curr = head;
    while(curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
  int n;
  cin >> n;
  struct Node* head = NULL;
  for(int i=0;i<n;i++)
  {
      int temp;
      cin >> temp;
      head = insert(head,temp);
  }
  head = reverseLinkedList(head);
  disp(head);
    return 0;
}
