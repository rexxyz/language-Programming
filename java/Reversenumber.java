import java.util.Scanner;
public class Reversenumber {
    public static void main(String[] args) {
        int number,remender,reverse=0;
        Scanner sc= new Scanner(System.in);
        System.out.print("enter the number :- ");
        number=sc.nextInt();
        while(number>0 || number<0)
        {
            remender=number%10;
            number=number/10;
            reverse=reverse*10+remender;
        }
        System.out.print("reverse number is :- "+reverse);
    }
}
