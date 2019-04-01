import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		int A = 100;
		int B = 100;
		
		int N = in.nextInt();
		for (int i = 0, a, b; i < N; ++i)
		{
			a = in.nextInt();
			b = in.nextInt();
			
			if (a > b) B -= a;
			if (b > a) A -= b;
		}
		
		System.out.println(A);
		System.out.println(B);
	}
}