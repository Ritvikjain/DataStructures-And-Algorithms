import java.util.*;
class HashSetDemo
{
	public  static void main(String[] args)
	{
		HashSet<String> h = new HashSet<String>();
		//Adding items to the list
		h.add("name1");
		h.add("name2");
		h.add("name3");
		h.add("name4");
		h.add("name5");
		
		//display the hashset
		System.out.println(h);
		
		//check if item is in HashSet 
		System.out.println("does List contains name2:"+h.contains("name2"));
		
		//Removing Item from the list
		h.remove("name3");
		
		//Iterating 
		Iterator<String> i = h.iterator();
		while(i.hasNext())
		{
			System.out.println(i.next());
		}
	}
}