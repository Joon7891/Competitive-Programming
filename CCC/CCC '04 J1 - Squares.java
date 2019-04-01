import java.io.*;
import java.util.*;

public class Main 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int ans = (int)Math.floor(Math.sqrt(N));
        
        System.out.println("The largest square has side length " + ans + ".");
    }
}