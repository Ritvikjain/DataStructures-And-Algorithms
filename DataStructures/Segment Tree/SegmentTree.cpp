#include<bits/stdc++.h>
using namespace std;
void buildTree(int *arr,int *tree,int start,int end,int treeNode){
	if(start == end)
	{
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}
void updateTree(int * arr,int *tree,int start,int end,int treeNode,int idx,int value)
{
	if(start == end)
	{
		arr[idx] = value;
		tree[treeNode] = value;
		return;
	}
	int mid = (start+end)/2;
	
	if(idx > mid)
	{
		updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
	}else{
		updateTree(arr,tree,start,mid,2*treeNode,idx,value);
	}
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}
int query(int* tree,int start,int end,int treeNode,int left,int right)
{
	//completely outside
	if(start>right || end<left)
		return 0;
	//completely inside
	if(start>=left && end<=right)
		return tree[treeNode];
	//partially inside and partially outside
	int mid = (start+end)/2;
	int ans1 = query(tree,start,mid,2*treeNode,left,right);
	int ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
	return ans1+ans2; 
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int *tree = new int[18];
	buildTree(arr,tree,0,8,1);
	for(int i=1;i<18;i++)
	{
		cout << tree[i] << endl;
	}
	updateTree(arr,tree,0,8,1,4,10);
	for(int i=1;i<18;i++)
	{
		cout << tree[i] << endl;
	}
	cout << "Query Solution :" << query(tree,0,8,1,0,2);
	return 0;
}
