#include<bits/stdc++.h>
using namespace std;
struct node{
    int evenCount;
    int oddCount;
};
void buildTree(int *arr,node *tree,int start,int end,int treeNode)
{
    if(start == end)
    {
        if(arr[start]%2 == 0)
            tree[treeNode].evenCount = 1;
        else
            tree[treeNode].oddCount = 1;
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode].evenCount = tree[2*treeNode].evenCount + tree[2*treeNode+1].evenCount;
    tree[treeNode].oddCount = tree[2*treeNode].oddCount + tree[2*treeNode+1].oddCount;
    return;
}
void update(int * arr,node* tree,int start,int end,int treeNode,int idx,int val)
{
    if(start == end)
    {
        arr[idx] = val;
        if(val%2 == 0)
        {
            tree[treeNode].evenCount = 1;
            tree[treeNode].oddCount = 0;
        }
        else
        {
            tree[treeNode].evenCount = 0;
            tree[treeNode].oddCount = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    if(idx > mid)
        update(arr,tree,mid+1,end,2*treeNode+1,idx,val);
    else
        update(arr,tree,start,mid,2*treeNode,idx,val);
    tree[treeNode].evenCount = tree[2*treeNode].evenCount + tree[2*treeNode+1].evenCount;
    tree[treeNode].oddCount = tree[2*treeNode].oddCount + tree[2*treeNode+1].oddCount;
    return;
}
node query(node *tree,int start,int end,int treeNode,int left,int right){
    //not in range
    if(start>right || end<left)
    {
        node res;
        res.evenCount = 0;
        res.oddCount = 0;
        return res;
    }
    //in range
    if(start>=left && end<=right)
        return tree[treeNode];
    //partially in range
    int mid = (start+end)/2;
    node ans1 = query(tree,start,mid,2*treeNode,left,right);
    node ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    node ans;
    ans.evenCount = ans1.evenCount + ans2.evenCount;
    ans.oddCount = ans1.oddCount + ans2.oddCount;
    return ans;
}
int main() {

	// Write your code here
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    node * tree = new node[4*n];
    buildTree(arr,tree,0,n-1,1);
    int nq;
    cin >> nq;
    while(nq--){
        int op;
        cin >> op;
        if(op == 0)
        {
            int ind,x;
            cin >> ind >> x;
            update(arr,tree,0,n-1,1,ind-1,x);
        }
        else{
            int left,right;
            cin >> left >> right;
            node ans = query(tree,0,n-1,1,left-1,right-1);
            if(op == 1)
                cout << ans.evenCount << endl;
            else
                cout << ans.oddCount << endl;
        }
    }
}
