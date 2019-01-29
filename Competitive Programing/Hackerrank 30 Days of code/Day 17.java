import java.util.*;
import java.io.*;
import java.lang.Math;
//Write your code here
class MyException extends Exception 
{ 
    public MyException(String s) 
    { 
        // Call constructor of parent Exception 
        super(s); 
    } 
}
class Calculator{
    int n;
    int p;
    int power(int n,int p) throws MyException
    {
        this.n = n;
        this.p = p;
        if(n<0||p<0)
        {
            throw new MyException("n and p should be non-negative");
        }
        return (int)Math.pow(n,p);
    }
}
class Solution{

    public static void main(String[] args) {
    
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
        
            int n = in.nextInt();
            int p = in.nextInt();
            Calculator myCalculator = new Calculator();
            try {
                int ans = myCalculator.power(n, p);
                System.out.println(ans);
            }
            catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        in.close();
    }
}
