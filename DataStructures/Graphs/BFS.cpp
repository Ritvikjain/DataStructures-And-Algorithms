#include<bits/stdc++.h>
#include<queue>
using namespace std;
void printBFS(int ** edges,int n,int sv,bool * visited)
{
	queue<int> pending;
	pending.push(sv);
	visited[sv] = true;
	while(!pending.empty()){
		int currentInd = pending.front();
		pending.pop();
		cout << currentInd << endl;
		for(int i=0;i<n;i++)
		{
			if(edges[currentInd][i] == 1 && !visited[i]){
				pending.push(i);
				visited[i] = true;
			}
		}
	}
}
void BFS(int ** edges,int n)
{
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			printBFS(edges,n,i,visited);
	}
	delete [] visited;
}
int main()
{
	int n,e;
	cin >> n >> e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
			edges[i][j] = 0;
	}
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin >> x >> y;
		edges[x][y] = 1;
		edges[y][x] = 1;
	}
	BFS(edges,n);
	
	for(int i=0;i<n;i++)
		delete [] edges[i];
	delete [] edges;
	return 0;
}
