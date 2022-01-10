import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OccurenceOfDigit {
    static int digit[]=new int[10];
    public static void init(){
        for(int i=0;i<10;i++){
            digit[i]=0;
        }
    }
    public static void occurence(long number){
        if(number==0)
            digit[0]++;
        while(number>0){
            digit[(int)(number%10)]++;
            number=number/10;
        }
    }
    public static void main(String args[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the positive integer numbers: ");
        long number = Long.parseLong(br.readLine());
        if(number<0){
            System.out.println("You have entered a negative number..!!!");
            return;
        }
        init();
        occurence(number);
        System.out.println("Occurence of "+number+" are: ");
        for(int i=0;i<10;i++){
            if(digit[i]>0)
                System.out.println(i+" has occured "+digit[i]+" times.");
        }
    }
}
