import java.io.*;
import java.util.*;

public class Main 
{	
	static Scanner in = new Scanner(System.in);
		
	public static void main(String[] args) 
	{
		double weight = in.nextDouble();
		double height = in.nextDouble();
		double BMI = weight / (height * height);
		
		if (BMI > 25)
		{
			System.out.println("Overweight");
		}
		else if (BMI >= 18.5)
		{
			System.out.println("Normal weight");
		}
		else
		{
			System.out.println("Underweight");
		}
	}
}