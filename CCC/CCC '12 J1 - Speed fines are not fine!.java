import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) 
	{
		int limit = in.nextInt();
		int rec = in.nextInt();
		
		if (rec <= limit)
		{
			System.out.println("Congratulations, you are within the speed limit!");
		}
		else if (rec - 20 <= limit)
		{
			System.out.println("You are speeding and your fine is $100.");
		}
		else if (rec - 30 <= limit)
		{
			System.out.println("You are speeding and your fine is $270.");
		}
		else
		{
			System.out.println("You are speeding and your fine is $500.");
		}
	}
}