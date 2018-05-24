import java.util.*;
class TestClass
{
	static void printSubsets(int set[])
	{
		int n=set.length;
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<n;j++)
			{
				if((i&(1<<j))>0)
				System.out.print(set[j]+" ");
			}
			System.out.println();
		}
	}
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		//char set[]=str.toCharArray();
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
		}
		printSubsets(arr);
	}
}