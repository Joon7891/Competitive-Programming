import java.io.*;
import java.util.*;

public class Main 
{		
	static Scanner in = new Scanner(System.in);
		
	static int H, M;
	
	public static void main(String[] args)
	{
		H = in.nextInt();
		M = in.nextInt();
		
		for (int i = 1; i <= M; ++i)
		{
			if (A(i) <= 0)
			{
				System.out.println("The balloon first touches ground at hour:\n" + i);
				return;
			}
		}
		
		System.out.println("The balloon does not touch ground in the given time.");
	}
	
	public static int A(int t)
	{
		return -6 * t * t * t * t + H * t * t * t + 2 * t * t + t;
	}
}