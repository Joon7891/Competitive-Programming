import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) 
	{
		int w = 0;
		for (int i = 0; i < 6; ++i) if (in.nextLine().equals("W")) w++;
		
		if (w > 4) System.out.println(1);
		else if (w > 2) System.out.println(2);
		else if (w > 0) System.out.println(3);
		else System.out.println(-1);
	}
}