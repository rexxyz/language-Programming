import java.util.*;
public class InverseNumber {
    public static void main(String[] args) {
        int rem,count=0;
        int ans=0;
        Scanner sc = new Scanner(System.in);
        System.out.print("enter any number:- ");
        int n = sc.nextInt();
        while(n>0) {
            rem=n%10;
            count++;
            n=n/10;
            ans=ans+(count*(int)Math.pow(10, (rem-1)));
        }
        System.out.println(ans);
    }
}
