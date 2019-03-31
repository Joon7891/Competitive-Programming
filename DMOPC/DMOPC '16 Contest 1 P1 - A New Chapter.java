import java.io.*;
import java.util.*;

public class Main 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int count = 0;
        for (int i = 0, x; i < N; ++i)
        {
            x = sc.nextInt();

            if ((x & 1) == (i & 1)) count++;
        }

        System.out.println(count);
    }
}