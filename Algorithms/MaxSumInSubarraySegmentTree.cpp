#include<bits/stdc++.h>
using namespace std;
struct node{
    long long maxSum;
    long long sum;
    long long bps;
    long long bss;
};
void buildTree(long long * arr,node * tree,int start,int end,int treeNode)
{
    if(start == end)
    {
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].sum = arr[start];
        tree[treeNode].bps = arr[start];
        tree[treeNode].bss = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    node left = tree[2*treeNode];
    node right = tree[2*treeNode+1];
    tree[treeNode].sum = left.sum + right.sum;
    tree[treeNode].bps = max(left.bps,left.sum+right.bps);
    tree[treeNode].bss = max(right.bss,right.sum+left.bss);
    long long maxSum = max(left.maxSum,right.maxSum);
    maxSum = max(maxSum,left.sum+right.bps);
    maxSum = max(maxSum,right.sum+left.bss);
    tree[treeNode].maxSum = max(maxSum,left.bss+right.bps);
    return ;
}
node query(node * tree,int start,int end,int treeNode,int left,int right)
{
    //not in range
    if(start>right || end<left)
    {
        node n;
        n.maxSum = INT_MIN;
        n.sum = INT_MIN;
        n.bss = INT_MIN;
        n.bps = INT_MIN;
        return n;
    }
    //in range
    if(start>=left && end<=right)
        return tree[treeNode];
    // partially in range
    int mid = (start+end)/2;
    node ans1 = query(tree,start,mid,2*treeNode,left,right);
    node ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    node ans;
    ans.sum = ans1.sum + ans2.sum;
    ans.bps = max(ans1.bps,ans1.sum+ans2.bps);
    ans.bss = max(ans2.bss,ans2.sum+ans1.bss);
    long long maxSum = max(ans1.maxSum,ans2.maxSum);
    maxSum = max(maxSum,ans1.sum+ans2.bps);
    maxSum = max(maxSum,ans2.sum+ans1.bss);
    ans.maxSum = max(maxSum,ans1.bss+ans2.bps);
    return ans;
}
int main() {

	// Write your code here
    int n;
    cin >> n;
    long long arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    node *tree = new node[4*n];
    buildTree(arr,tree,0,n-1,1);
    int nq;
    cin >> nq;
    while(nq--)
    {
        int x,y;
        cin >> x >> y;
        cout << query(tree,0,n-1,1,x-1,y-1).maxSum << endl;
    }
}
