import java.io.*;
import java.util.*;

public class Main 
{		
	static Scanner in = new Scanner(System.in);
	
	static int[][] grid = new int[4][4];
	
	public static void main(String[] args)
	{
		int X = in.nextInt();
		int Y = in.nextInt();
		int Z = in.nextInt();
		
		int ans = (X / Z) * (Y / Z);
		System.out.println(ans);
	}
}