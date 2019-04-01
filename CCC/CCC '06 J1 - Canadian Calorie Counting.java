import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	static int[] a = { 461, 431, 420, 0 };
	static int[] b = { 100, 57, 70, 0 };
	static int[] c = { 130, 160, 118, 0 };
	static int[] d = { 167, 266, 75, 0 };
	
	public static void main(String[] args) 
	{
		int total = a[in.nextInt() - 1] + b[in.nextInt() - 1] + c[in.nextInt() - 1] + d[in.nextInt() - 1];
		
		System.out.println("Your total Calorie count is " + total + ".");
	}
}