import java.util.Scanner;
public class primeNumber {
    public static void main(String[] args) {
        int count = 0;
        int num;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter any number");
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
            count++;
        }
        if (count <= 2)
            System.out.println(" prime ");

        else
            System.out.println(" not prime");


    }

}
