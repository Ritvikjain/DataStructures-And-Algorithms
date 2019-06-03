#include <iostream>
using namespace std;
bool findPathExistence(int ** edges,int n,int sv,int ev,bool * visited)
{
    if(sv == ev)
        return true;
    visited[sv] = true;
    bool ans = false;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i] == 1 && !visited[i])
        {
            ans = findPathExistence(edges,n,i,ev,visited);
        }
    }
    return ans;
}
int main() {
    int n, E;
    cin >> n >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int ** edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
            edges[i][j] = 0;
    }
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin >> x >> y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }
    bool * visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    int sv,ev;
    cin >> sv >> ev;
    if(findPathExistence(edges,n,sv,ev,visited))
        cout << "true";
    else
        cout << "false";
    delete [] visited;
    for(int i=0;i<n;i++)
        delete [] edges[i];
    delete [] edges;
  return 0;
}

