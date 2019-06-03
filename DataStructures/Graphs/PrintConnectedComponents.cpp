#include <bits/stdc++.h>

using namespace std;
vector<int> BFSPath(int ** edges,int n,int sv,bool * visited)
{
    vector<int> res;
	queue<int> pending;
    res.push_back(sv);
	pending.push(sv);
	visited[sv] = true;
	while(!pending.empty()){
		int currentInd = pending.front();
		pending.pop();
		for(int i=0;i<n;i++)
		{
			if(edges[currentInd][i] == 1 && !visited[i]){
				pending.push(i);
                res.push_back(i);
				visited[i] = true;
			}
		}
	}
    sort(res.begin(),res.end());
    return res;
}
vector< vector<int> > connectedComponents(int ** edges,int n,int sv,bool * visited)
{
    vector< vector<int> > output;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> res = BFSPath(edges,n,i,visited);
            output.push_back(res);
        }
    }
    return output;
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
        cin >> tempX >> tempY;
        edges[tempX][tempY] = 1;
        edges[tempY][tempX] = 1;
    }
    bool * visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    vector< vector<int> > res = connectedComponents(edges,V,0,visited);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
  return 0;
}

