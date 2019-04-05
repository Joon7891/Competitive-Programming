import java.io.*;
import java.util.*;

public class Main 
{		
	static Scanner in = new Scanner(System.in);

	static int[] v;
	static int N;
	
	public static void main(String[] args)
	{
		N = in.nextInt();
		while (N != 0)
		{
			v = new int[N];
			for (int i = 0; i < N; ++i) v[i] = in.nextInt();
			
			if (N > 1)
			{
				for (int len = 1; len < N; ++len)
				{
					int[] cycle = new int[len];
					for (int i = 0; i < len; ++i) cycle[i] = v[i + 1] - v[i];
					
					boolean sat = true;
					for (int i = 0; i < N - 1; ++i)
					{
						if (v[i + 1] - v[i] != cycle[i % len])
						{
							sat = false;
							break;
						}
					}
					
					if (sat)
					{
						System.out.println(len);
						break;
					}
				}
			}
			else
			{
				System.out.println(0);
			}
			
			N = in.nextInt();
		}
	}
}