import java.io.*;
import java.util.*;

public class Main 
{		
	static Scanner in = new Scanner(System.in);
	
	static int[][] grid = new int[4][4];
	
	public static void main(String[] args)
	{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				grid[i][j] = in.nextInt();
			}
		}
		
		int sum = 0;
		for (int i = 0; i < 4; ++i)
		{
			sum += grid[0][i];
		}
		
		boolean magic = true;
		for (int i = 0; i < 4; ++i)
		{
			int newSum = 0;
			for (int j = 0; j < 4; ++j)
			{
				newSum += grid[i][j];
			}
			
			magic = magic && (sum == newSum);
			
			newSum = 0;
			for (int j = 0; j < 4; ++j)
			{
				newSum += grid[j][i];
			}
			
			magic = magic && (sum == newSum);
		}
		
		System.out.println(magic ? "magic" : "not magic");
	}
}
