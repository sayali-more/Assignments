import java.io.BufferedReader;
import java.io.IOException;

public class CountOfDigit
{
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(System.in());
        System.out.print("Enter interger number: ");
        int num = Integer.parseInt(br.readLine());
        for(int i=1,n=num ; n > 0;i++ )
        {
                n = n % 10;
        }
        System.out.println("Count of "+num+"is : "+i);
    }
}