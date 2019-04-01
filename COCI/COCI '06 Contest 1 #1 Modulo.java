import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		HashSet<Integer> set = new HashSet<Integer>();
		
		for (int i = 0, x; i < 10; ++i)
		{
			x = in.nextInt() % 42;
			set.add(x);
		}
		
		System.out.println(set.size());
	}
}