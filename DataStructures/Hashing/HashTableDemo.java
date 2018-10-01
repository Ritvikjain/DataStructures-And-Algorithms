import java.util.*;
class HashTableDemo{
	public static void main(String args[])
	{
		Hashtable h = new Hashtable();

		h.put("1", "one");
		h.put("2", "two");
		h.put("3", "three");
		h.put("4", "four");

		//display hashtable
		System.out.println("values in hashtable : " + h);

		//display keys
		Enumeration keys;
		keys = h.keys();
		String str;
		int i=0;
		String arr[]= new String[h.size()];
		System.out.println("keys of hashtable :");
		while(keys.hasMoreElements())
		{
			str = (String) keys.nextElement();
			arr[i] = str;
			System.out.print(arr[i]+" ");
			i++;
		}

		//cloning hashtable
		Hashtable h2 = (Hashtable)h.clone();
		System.out.println(h2);
	}
}