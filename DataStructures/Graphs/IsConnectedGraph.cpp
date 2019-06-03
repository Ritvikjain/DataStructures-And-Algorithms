#include <iostream>
using namespace std;
void DFSPath(int ** edges,int n,int sv,bool * visited)
{
    visited[sv] = true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i] == 1 && !visited[i])
            DFSPath(edges,n,i,visited);
    }
}
bool isConnected(bool * visited,int n)
{
    for(int i=0;i<n;i++)
        if(!visited[i])
            return false;
    return true;
}
int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int ** edges = new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
            edges[i][j] = 0;
    }
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin >> x >> y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }
    bool * visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    DFSPath(edges,V,0,visited);
    if(isConnected(visited,V))
        cout << "true" ;
    else
        cout << "false" ;
    delete [] visited;
    for(int i=0;i<V;i++)
        delete [] edges[i];
    delete [] edges;

  return 0;
}

