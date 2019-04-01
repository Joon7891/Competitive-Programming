import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		String line = in.nextLine();
		
		int a = 0, b = 0;
		for (int i = 0; i < line.length() - 2; ++i)
		{
			String substr = line.substring(i, i + 3);
			
			if (substr.equals(":-)")) a++;
			else if (substr.equals(":-(")) b++;
		}
		
		if (a == 0 && b == 0) System.out.print("none");
		else if (a == b) System.out.print("unsure");
		else if (a > b) System.out.print("happy");
		else System.out.print("sad");
	}
}