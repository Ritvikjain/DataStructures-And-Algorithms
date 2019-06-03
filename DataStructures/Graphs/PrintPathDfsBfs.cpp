#include <bits/stdc++.h>
using namespace std;
vector<int> DFSPath(int ** edges,int n,int sv,int ev,bool * visited){
    if(sv == ev)
    {
        vector<int> res;
        res.push_back(ev);
        return res;
    }
    visited[sv] = true;
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i] == 1 && !visited[i])
        {
            res = DFSPath(edges,n,i,ev,visited);
            if(res.size() != 0)
            {
                res.push_back(sv);
                return res;
            }
        }
    }
    return res;
}
vector<int> BFSPath(int ** edges,int n,int sv,int ev,bool * visited)
{
    map<int,int> path;
    vector<int> res;
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    while(!pending.empty())
    {
        int ind = pending.front();
        if(ind == ev)
            break;
        pending.pop();
        for(int i=0;i<n;i++)
        {
            if(edges[ind][i] == 1 && !visited[i])
            {
                path[i] = ind;
                pending.push(i);
                visited[i] = true;
                // if(i == ev)
                //     break;
            }
        }
        // if(pending.back() == ev)
        //     break;
    }
    if(pending.empty())
        return res;
    else{
        int pos = ev;
        res.push_back(pos);
        while(path[pos] != sv)
        {
            pos = path[pos];
            res.push_back(pos);
        }
        res.push_back(sv);
        return res;
    }
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
        int x,y;
        cin >> x >> y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }
    cin >> tempX >> tempY;
    bool * visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    vector<int> result = DFSPath(edges,V,tempX,tempY,visited);
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
    delete [] visited;
    for(int i=0;i<V;i++)
        delete [] edges[i];
    delete [] edges;
  return 0;
}

