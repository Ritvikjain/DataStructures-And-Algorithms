#include <bits/stdc++.h>
using namespace std;
struct Node 
{ 
    string name; 
    vector<Node *>child; 
};
Node* find(Node* root,string name)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->name == name)
        return root;
    Node * ans = NULL;
    for(int i=0;i<root->child.size();i++)
    {
        ans = find(root->child[i],name);
        if(ans!=NULL)
        {
            return ans;
        }
    }
    return ans;
}
Node* newNode(string name) 
{ 
    Node *temp = new Node; 
    temp->name = name; 
    return temp; 
} 
int findChild(Node* temp,string name)
{
    if(temp == NULL)
    {
        return -1;
    }
    if(temp->name == name)
    {
        return 0;
    }
    for(int i=0;i<temp->child.size();i++)
    {
        int ans = findChild(temp->child[i],name);
        if(ans!=-1)
            return ans+1;
    }
    return -1;
}
int main ()
{
    Node* root = NULL;
    string name;
    while(cin >> name)
    {
        if(name == "STOP")
        {
            break;
        }
        int n;
        cin >> n;
        vector<string> child;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin >> temp;
            child.push_back(temp);
        }
        Node* temp = find(root,name);
        if(temp == NULL)
        {
            root = new Node;
            root->name = name;
            for(int i=0;i<child.size();i++)
            {
                root->child.push_back(newNode(child[i]));
            }
        }
        else{
            for(int i=0;i<n;i++)
            {
                temp->child.push_back(newNode(child[i]));
            }
        }
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string name1,name2;
        cin >> name1 >> name2;
        Node* temp = find(root,name1);
        int ans = findChild(temp,name2);
        if(ans < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES " << ans << endl;
    }
    return 0;
}
