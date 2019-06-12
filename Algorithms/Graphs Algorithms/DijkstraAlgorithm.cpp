#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool * visited,int * distance,int n)
{
    int minVertex = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex == -1 || distance[minVertex] > distance[i]))
            minVertex = i;
    }
    return minVertex;
}
void dijkstras(int ** edges,int n)
{
    bool * visited = new bool[n]();
    int * distance = new int[n];
    for(int i=0;i<n;i++)
    {
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for(int i=0;i<n-1;i++)
    {
        int minVertex = getMinVertex(visited,distance,n);
        visited[minVertex] = true;
        
        for(int j=0;j<n;j++)
        {
            if(edges[minVertex][j] != 0 && !visited[j])
            {
                if(distance[j] > distance[minVertex] + edges[minVertex][j])
                {
                    distance[j] = distance[minVertex] + edges[minVertex][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << i << " " << distance[i] << endl;
    }
    delete [] distance;
    delete [] visited;
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
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
        int wt;
        cin >> tempX >> tempY >> wt;
        edges[tempX][tempY] = wt;
        edges[tempY][tempX] = wt;
    }
    dijkstras(edges,V);
    for(int i=0;i<V;i++)
        delete [] edges[i];
    delete [] edges;
  return 0;
}

