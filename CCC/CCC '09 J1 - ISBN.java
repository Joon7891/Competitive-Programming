import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) 
	{
		int total = 91;
		total += in.nextInt();
		total += 3 * in.nextInt();
		total += in.nextInt();
		
		System.out.println("The 1-3-sum is " + total);
	}
}