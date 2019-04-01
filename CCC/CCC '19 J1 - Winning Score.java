import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
	
	public static void main(String[] args) 
	{
		int A = 0;
		int B = 0;
		
		A += 3 * in.nextInt();
		A += 2 * in.nextInt();
		A += in.nextInt();
		
		B += 3 * in.nextInt();
		B += 2 * in.nextInt();
		B += in.nextInt();
		
		if (A > B) System.out.println("A");
		else if (B > A) System.out.println("B");
		else System.out.println("T");
	}
}
