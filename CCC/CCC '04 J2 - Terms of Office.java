import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		int N = in.nextInt();
		int M = in.nextInt();
		
		while (N <= M)
		{
			System.out.println("All positions change in year " + N);
			N += 60;
		}
	}
}