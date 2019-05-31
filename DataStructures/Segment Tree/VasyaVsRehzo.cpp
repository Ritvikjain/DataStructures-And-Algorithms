#include<bits/stdc++.h>
using namespace std;
struct input{
    int A,B;
};
struct node{
    int ind;
    int A;
    int B;
};
void buildTree(input *arr,node *tree,int start,int end,int treeNode){
    if(start == end)
    {
        tree[treeNode].ind = start;
        tree[treeNode].A = arr[start].A;
        tree[treeNode].B = arr[start].B;
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    node left = tree[2*treeNode];
    node right = tree[2*treeNode+1];
    if(left.A != right.A)
    {
        if(left.A > right.A)
            tree[treeNode] = left;
        else
            tree[treeNode] = right;
    }
    else if(left.B != right.B){
        if(left.A < right.A)
            tree[treeNode] = left;
        else
            tree[treeNode] = right;
    }
    else{
        if(left.ind < right.ind)
            tree[treeNode] = left;
        else
            tree[treeNode] = right;
    }
}
node query(node *tree,int start,int end,int treeNode,int left,int right)
{
    //not in range
    if(start>right || end<left)
    {
        node res;
        res.ind = INT_MAX;
        res.A = INT_MIN;
        res.B = INT_MAX;
        return res;
    }
    //in range
    if(start>=left && end<=right)
    {
        return tree[treeNode];
    }
    //partially in range
    int mid = (start+end)/2;
    node ans1 = query(tree,start,mid,2*treeNode,left,right);
    node ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    node ans;
    if(ans1.A != ans2.A)
    {
        if(ans1.A > ans2.A)
            ans = ans1;
        else
            ans = ans2;
    }
    else if(ans1.B != ans2.B){
        if(ans1.A < ans2.A)
            ans = ans1;
        else
            ans = ans2;
    }
    else{
        if(ans1.ind < ans2.ind)
            ans = ans1;
        else
            ans = ans2;
    }
    return ans;
}
int main() {

	// Write your code here
    int n;
    cin >> n;
    input arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i].A;
    for(int i=0;i<n;i++)
        cin >> arr[i].B;
    node *tree = new node[4*n];
    buildTree(arr,tree,0,n-1,1);
    int nq;
    cin >> nq;
    while(nq--){
        int left,right;
        cin >> left >> right;
        cout << query(tree,0,n-1,1,left-1,right-1).ind+1 << endl;
    }
}
