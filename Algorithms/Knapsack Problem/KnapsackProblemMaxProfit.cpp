#include <iostream>
using namespace std;
struct Bag{
	double p,w;
};
void sortBag(struct Bag bag[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(bag[i].p<bag[j].p)
			{
				struct Bag temp = bag[i];
				bag[i] = bag[j];
				bag[j] = temp;
			}
		}
	}
}
double maxProfit(struct Bag bag[],int n,double weight)
{
	double profit = 0;
	int i = 0;
	while(i<n&&bag[i].w<=weight)
	{
		profit += bag[i].p;
		weight -= bag[i].w;
		i++;
	}
	if(i<n&&weight!=0)
	{
		profit += (weight/bag[i].w)*bag[i].p;
		weight = 0;
	}
	return profit;
}
int main()
{
	int n;
	double weight;
	cin>>n>>weight;
	struct Bag bag[n];
	for(int i=0;i<n;i++)
	{
		cin>>bag[i].p>>bag[i].w;
	}
	sortBag(bag,n);
	for(int i=0;i<n;i++)
	cout<<bag[i].p<<" ";
	cout<<maxProfit(bag,n,weight);
}
