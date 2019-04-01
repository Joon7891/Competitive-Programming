import java.io.*;
import java.util.*;
import java.awt.geom.*;

public class Main 
{
	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		int xr = sc.nextInt(); 
		int yr = sc.nextInt();
		int xj = sc.nextInt();
		int yj = sc.nextInt();
		
		int N = sc.nextInt();
		int counter = 0;
		for (int i = 0, K; i < N; ++i)
		{
			K = sc.nextInt();
			int[] xs = new int[K];
			int[] ys = new int[K];
			
			for (int j = 0; j < K; ++j)
			{
				xs[j] = sc.nextInt();
				ys[j] = sc.nextInt();
			}
			
			for (int j = 0; j < K; ++j)
			{
				if (Line2D.linesIntersect(xr, yr, xj, yj, xs[j], ys[j], xs[(j + 1) % K], ys[(j + 1) % K]))
				{
					counter++;
					break;
				}
			}
		}
		
		System.out.println(counter);
	}
}