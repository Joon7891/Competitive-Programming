import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) 
	{
		int month = in.nextInt();
		int day = in.nextInt();
		
		if (month == 2)
		{
			if (day == 18)
			{
				System.out.println("Special");
			}
			else if (day < 18)
			{
				System.out.println("Before");
			}
			else
			{
				System.out.println("After");
			}
		}
		else if (month < 2)
		{
			System.out.println("Before");
		}
		else
		{
			System.out.println("After");
		}
	}
}