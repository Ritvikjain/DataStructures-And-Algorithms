import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception 
    {
        
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++)
        {
            int n=sc.nextInt();
            int a[]=new int[n];
            int sum=0;
            for(int j=0;j<n;j++)
            {
                a[j]=sc.nextInt();
                sum=sum+a[j];
            }
            System.out.println(sum);
        }

    }
}
