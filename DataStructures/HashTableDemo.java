import java.util.*;
class HashTableDemo{
	public static void main(String args[])
	{
		Hashtable h=new Hashtable();
		h.put(3,"Raj");
		h.put(2,"Ritvik");
		h.put(1,"Rohan");
		
		System.out.println(h);
		
		Hashtable h1=new Hashtable();
		h1=(Hashtable)h.clone();
		System.out.println("After Clonning: "+h1);
	}
}