import java.io.*;
import java.util.*;

public class Main 
{		
	static Scanner in = new Scanner(System.in);
	
	static int N, M;
	static int[][] grid;
	static boolean[][] visited;
	
	public static void main(String[] args)
	{
		N = in.nextInt();
		M = in.nextInt();
		
		grid = new int[M][N];
		visited = new boolean[M][N];
		
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				grid[i][j] = in.nextInt();
			}
		}
				
		int combo = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j <= 10; ++j)
			{
				for (int k = 0; k <= 10; ++k)
				{
					combo++;
					if (solve(i, j, k))
					{
						System.out.println(i + " " + j + " " + k);
						return;
					}
				}
			}
		}
		
		System.out.println("-1 -1 -1");
	}
	
	public static boolean solve(int a, int b, int c)
	{
		for (int start = 0; start < N; ++start)
		{
			for (int i = 0; i < M; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					visited[i][j] = false;
				}
			}
						
			Queue<int[]> q = new LinkedList<int[]>();
			q.add(new int[]{0, start});
			visited[0][start] = true;
			
			while (!q.isEmpty())
			{
				int[] cur = q.poll();
								
				if (cur[0] == M - 1) return true;
				
				if (cur[0] - 1 >= 0 && !visited[cur[0] - 1][cur[1]] &&
					(grid[cur[0] - 1][cur[1]] == a || grid[cur[0] - 1][cur[1]] == b ||
					grid[cur[0] - 1][cur[1]] == c))
				{
					visited[cur[0] - 1][cur[1]] = true;
					q.add(new int[]{cur[0] - 1, cur[1]});
				}		
				
				if (cur[0] + 1 < M && !visited[cur[0] + 1][cur[1]] &&
					(grid[cur[0] + 1][cur[1]] == a || grid[cur[0] + 1][cur[1]] == b ||
					grid[cur[0] + 1][cur[1]] == c))
				{
					visited[cur[0] + 1][cur[1]] = true;
					q.add(new int[]{cur[0] + 1, cur[1]});
				}	
				
				if (cur[1] + 1 < N && !visited[cur[0]][cur[1] + 1] &&
					(grid[cur[0]][cur[1] + 1] == a || grid[cur[0]][cur[1] + 1 ] == b ||
					grid[cur[0]][cur[1] + 1] == c))
				{
					visited[cur[0]][cur[1] + 1 ] = true;
					q.add(new int[]{cur[0], cur[1] + 1 });
				}
				
				if (cur[1] - 1 >= 0 && !visited[cur[0]][cur[1] - 1] &&
					(grid[cur[0]][cur[1] - 1] == a || grid[cur[0]][cur[1] - 1 ] == b ||
					grid[cur[0]][cur[1] - 1] == c))
				{
					visited[cur[0]][cur[1] - 1] = true;
					q.add(new int[]{cur[0], cur[1] - 1 });
				}
			}
		}
				
		return false;
	}
}