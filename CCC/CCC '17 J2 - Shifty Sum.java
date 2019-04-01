import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		int N = in.nextInt();
		int K = in.nextInt();
		
		int total = N;
		for (int i = 0; i < K; ++i)
		{
			N *= 10;
			total += N;
		}
		
		System.out.println(total);
	}
}