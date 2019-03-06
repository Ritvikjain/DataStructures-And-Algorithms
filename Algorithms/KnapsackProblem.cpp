//Knapsack Problem
#include <iostream>
#include <cstdlib>
using namespace std;
struct Bag{
	double p,w;
};
int compare(struct Bag* a,struct Bag* b)
{
	double x = a->p/a->w;
	double y = b->p/b->w;
	if(x==y)
		return 0;
	else if(x>y)
		return -1;
	else
		return 1;
}
int main()
{
	int n,bagsize;
	//userinput no. of elements in bag and bagsize
	cin>>n>>bagsize;
	struct Bag bag[n];
	//profit input of all elememts
	for(int i=0;i<n;i++)
	{
		cin>>bag[i].p;
	}
	//weight input of all element
	for(int i=0;i<n;i++)
	{
		cin>>bag[i].w;
	}
	//quick sort on p/w ratio
	qsort(bag,n,sizeof(struct Bag),compare);
	int i = 0;
	double p = 0 ;
	while(i<n&&bagsize>=bag[i].w)
	{
		p = p+bag[i].p;
		bagsize = bagsize-bag[i].w;
	}
	if(i<n&&bagsize>0)
	{
		p = p+bag[i].p*bagsize/(double)bag[i].w;
	}
	if(i==n&&bagsize>0)
	{
		cout<<"Not enough elements"<<endl;
	}
	cout<<"Profit :"<<p;
}
