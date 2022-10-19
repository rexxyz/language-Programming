import java.util.Scanner;
public class Alprimenumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter two number // smaller & greayer :=");
        int smaller = sc.nextInt();
        int bigger = sc.nextInt();
        for (int i = smaller; i <= bigger; i++) {
            int count = 0;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    count++;
                    break;
                }
            }
            if (count == 0) {
                System.out.println(i);
            }
        }
    }
}
