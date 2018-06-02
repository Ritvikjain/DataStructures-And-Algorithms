
public class Stack 
{
	int maxSize;
	int top;
	String arr[];
	public Stack(int n) 
	{
		maxSize=n;
		arr=new String[maxSize];
		top=0;
	}
	void Push(String n)
	{
		if(top<maxSize)
		{
			arr[top]=n;
			top++;
		}
		else
		{
			System.out.println("Overflow");
		}
	}
	void Pop()
	{
		if(top>=0)
		{
			top--;
		}
		else
		{
			System.out.println("Underflow");
		}
	}
}
