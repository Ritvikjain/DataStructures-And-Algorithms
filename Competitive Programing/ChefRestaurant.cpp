#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int> t1,vector<int> t2)
{
	return t1[0]<t2[0];
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector< vector<int> > time;
		for(int i=0;i<n;i++)
		{
			vector<int> row;
			int temp1,temp2;
			cin>>temp1>>temp2;
			row.push_back(temp1);
			row.push_back(temp2);
			time.push_back(row);
		}
		vector<int> person;
		for(int i=0;i<m;i++)
		{
			int temp;
			cin>>temp;
			person.push_back(temp);
		}
		sort(time.begin(),time.end(),cmp);
		vector<int> arr;
		vector<int> dept;
		for(int i=0;i<n;i++)
		{
			arr.push_back(time[i][0]);
			dept.push_back(time[i][1]);
		}
		for(int i=0;i<m;i++)
		{
			if(person[i] <= arr[0])
			{
				cout << arr[0] - person[i]<<endl;
			}
			else if(person[i] >= dept[n-1])
			{
				cout << -1<<endl;
			}
			else{
				vector<int> :: iterator lower = lower_bound(arr.begin(),arr.end(),person[i]);
				int ans = -1;
				int ind = lower - arr.begin();
				//cout<< person[i] <<" "<< ind <<endl;
				if( person[i] >= dept[ind-1] )
				{
					ans = time[ind][0] - person[i];
				}
				else 
				{
					ans = 0;
				}
				cout<<ans<<endl;
			}
		}
		
	}
	return 0;
}

/*
1
4 5
5 7
9 10
2 3
20 30
5
6
7
35
1
*/
