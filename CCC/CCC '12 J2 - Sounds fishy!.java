import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) 
	{
		int[] r = new int[4];
		
		for (int i = 0; i < 4; ++i) r[i] = in.nextInt();
		
		boolean rising = true;
		boolean diving = true;
		boolean constant = true;
		for (int i = 0; i < 3; ++i)
		{
			if (r[i] < r[i + 1])
			{
				diving = false;
				constant = false;
			}
			else if (r[i] > r[i + 1])
			{
				rising = false;
				constant = false;
			}
			else if (r[i] == r[i + 1])
			{
				rising = false;
				diving = false;
			}
		}

		if (constant) System.out.println("Fish At Constant Depth");
		else if (rising) System.out.println("Fish Rising");	
		else if (diving) System.out.println("Fish Diving");	
		else System.out.println("No Fish");	
	}
}