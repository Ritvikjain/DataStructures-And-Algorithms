#include <iostream>
#include <list>

using namespace std;

class Hash{
	int bucket;
	list<int> *table;
public:
	Hash(int v){
		bucket = v;
		table = new list<int>[bucket];
	}

	void insertItem(int key)
	{
		int index = hashFunction(key);
		table[index].push_back(key);
	}

	void deleteItem(int key)
	{
		int index = hashFunction(key);

		list<int> :: iterator i;
		for(i = table[index].begin();i!=table[index].end();i++)
		{
			if(*i == key)
				break;
		}

		if(i!=table[index].end())
		{
			table[index].erase(i);
		}
	}

	int hashFunction(int x){
		return (x % bucket);
	}

	/*void displayHash(){
		for(int i=0;i<bucket; i++)
		{
			cout<<i;
			for(auto x : table[i])
				cout<<"-->"<<x;
			cout<<endl;
		}
	}*/
};

int main()
{
	int a[] = {1,2,3,4,5};
	int n= sizeof(a)/sizeof(a[0]);

	Hash h(7);

	for(int i=0;i<n;i++)
	{
		h.insertItem(a[i]);
	}

	h.deleteItem(3);

	//h.displayHash();

	return 0;
}
