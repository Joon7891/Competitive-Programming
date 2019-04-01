import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	static String[] adj;
	static String[] noun;
	
	public static void main(String[] args) 
	{
		int N = Integer.parseInt(in.nextLine());
		int M = Integer.parseInt(in.nextLine());
		
		adj = new String[N];
		noun = new String[M];
		
		for (int i = 0; i < N; ++i) adj[i] = in.nextLine();
		for (int i = 0; i < M; ++i) noun[i] = in.nextLine();
		
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				System.out.println(adj[i] + " as " + noun[j]);
			}
		}
		
	}
}