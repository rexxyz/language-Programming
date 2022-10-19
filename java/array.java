import java.util.Scanner;

//import static com.sun.tools.javac.jvm.ByteCodes.swap;

public class array {
    public static void main(String[] args) {
        int arr[];
        int temp=0;
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the number you want");
        n = sc.nextInt();
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
        //System.out.println("bubble short is not completed yet  \uD83D\uDE25\uD83D\uDE25\uD83D\uDE25\uD83D\uDE25\uD83D\uDE25");
        int x = arr.length;
    }

    }

