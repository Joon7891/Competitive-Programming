import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	static int[] w = new int[3]; 
	
	public static void main(String[] args) 
	{
		for (int i = 0; i < 3; ++i) w[i] = in.nextInt();
		Arrays.parallelSort(w);
		
		System.out.println(w[1]);
	}
}