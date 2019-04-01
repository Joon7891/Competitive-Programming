import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) 
	{
		int a = in.nextInt();
		int e = in.nextInt();
		
		if (a >= 3 && e <= 4) System.out.println("TroyMartian");
		if (a <= 6 && e >= 2) System.out.println("VladSaturnian");
		if (a <= 2 && e <= 3) System.out.println("GraemeMercurian");
	}
}