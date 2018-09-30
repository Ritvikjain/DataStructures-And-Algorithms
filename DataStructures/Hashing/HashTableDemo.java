import java.util.*;
class HashTableDemo{
	public static void main(String args[])
	{
		Hashtable h = new Hashtable();

		h.put(1, "one");
		h.put(2, "two");
		h.put(3, "three");
		h.put(4, "four");

		System.out.println("values in hashtable : " + h);
	}
}