import java.util.*;
class SetDemo
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		Set<Integer> s=new HashSet<Integer>();
		for(int i=0;i<10;i++)
		{
			s.add(i);
		}
		System.out.println(s);
	}
}