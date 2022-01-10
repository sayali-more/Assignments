import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PerfectNumbers
{
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the limit for Perfect numbers: ");
        int limit = Integer.parseInt(br.readLine());
        int sum=0;
        System.out.print("Perfect number between 1 to "+limit+" is: ");
        for(int i=2; i<=limit ;i++)
        {   sum=0;
            for(int j=1; j<=i/2 ;j++)
            {
                if(i%j==0)
                    sum = sum+j;
            }
            if(sum==i)
                System.out.print(" "+i+" ");
        }
        System.out.println();
    }
}
