#include<bits/stdc++.h>
#include<queue>
using namespace std;
void printBFS(int ** edges,int n,int sv)
{
	bool * visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
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
	bool * visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
	printBFS(edges,n,0);
	return 0;
}
