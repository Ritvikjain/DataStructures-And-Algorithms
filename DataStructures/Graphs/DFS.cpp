#include<bits/stdc++.h>
using namespace std;
//For connected Graph
void printDFS(int ** edges,int n,int sv,bool * visited)
{
	cout << sv << endl;
	visited[sv] = true;
	for(int i=0;i<n;i++)
	{
		if(i == sv)
			continue;
		if(edges[sv][i] == 1 && !visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
}
//For Disconnected Graph
void DFS(int ** edges,int n){
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			printDFS(edges,n,i,visited);
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
	DFS(edges,n);
	for(int i=0;i<n;i++)
		delete [] edges[i];
	delete [] edges;
	return 0;
}
