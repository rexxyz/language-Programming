import com.sun.security.jgss.GSSUtil;

import java.util.Scanner;
public class Numcount {
    public static void main(String[] args) {
        int rem, input, find, count = 0;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any random number :- ");
        input= sc.nextInt();
        System.out.println("Enter the number you try to find");
        find= sc.nextInt();
        while(input>0) {
          rem=input%10;
          if(rem==find){
       count++;
        }
          input=input/10;

        }
        System.out.println("the came "+count+" time");
    }
}
