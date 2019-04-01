import java.io.*;
import java.util.*;

public class Main 
{		
	static Scanner in = new Scanner(System.in);
	
	static int[] v;
	static long M;
	static int N;
	
	public static void main(String[] args)
	{
		N = in.nextInt();
		M = in.nextLong();
		
		v = new int[N];
		for (int i = 0; i < N; ++i) v[i] = in.nextInt();
		
		int best = 0;
		int left = 0;
		int right = 0;
		long total = v[0];
		while (right < N)
		{			
			if (total < M)
			{
				best = Math.max(best, right - left + 1);
				if (right + 1 < N) total += v[++right];
				else break;
			}
			else
			{
				total -= v[left++];
			}
		}
		
		System.out.println(best);
	}
}
