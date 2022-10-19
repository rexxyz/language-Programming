import java.util.Scanner;
public class ArmStrong {
    public static void main(String[] args) {
        int rem,count=0;
        int ans = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter any number");
        int n = sc.nextInt();
        int temp=n;
        while (n>0){
          rem=n%10;
          ans=ans+(rem*rem*rem);
          n=n/10;
      }
if(temp==ans)
        System.out.println(temp+" is a Armstrong number ");
else
    System.out.println(temp+"  is not a Armstrong number");
    }
    }

