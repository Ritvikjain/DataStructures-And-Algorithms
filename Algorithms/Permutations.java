import java.util.*;
public class Permutations {
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		String str=sc.next();
		int n=str.length();
		permute(str,0,n-1);
	}
	static void permute(String str,int l,int r)
	{
		if(l==r)
		{
			System.out.println(str);
		}
		else
		{
			for(int i=l;i<=r;i++)
			{
				str=swap(str,l,i);
				permute(str,l+1,r);
				str=swap(str,l,i);
			}
		}
	}
	static String swap(String str,int l,int r)
	{
		char a[]=str.toCharArray();
		char temp=a[l];
		a[l]=a[r];
		a[r]=temp;
		str=String.valueOf(a);
		return str;
	}
}
