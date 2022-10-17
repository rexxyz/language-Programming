import java.util.Scanner;
public class Fibonacci {
    public static void main(String[] args) {
        int a=0;
        int b=1;
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter nth number:-");
        n=sc.nextInt();
        for (int i=0;i<n;i++){
            System.out.println(a);
            int febo=a+b;
            a=b;
            b=febo;
        }

    }
}
