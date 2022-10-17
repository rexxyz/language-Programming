import java.util.Scanner;
public class NumberRotation {
    public static void main(String[] args) {
        int digt=0;
        Scanner sc = new Scanner(System.in);
        System.out.print("enter any number :- ");
        int n = sc.nextInt();
        System.out.print("enter how many time you want to rotate the number :- ");
        int k =sc.nextInt();
        int temp=n;
        while(temp>0) {
            temp=temp/10;
            digt++;
        }
        k=k%digt;
        if(k<0){
            k=k+digt;

        }
        int mult=1;
        int div=1;
        // System.out.println("digt= "+digt+ "  and " +"k = "+k);
        for(int i=1;i<=digt; i++) {
            if(i<=k){
                div=div*10;
            }
            else {
                mult = mult*10;
            }
        }
        int q = n/div;
        int r = n%div;
        int ans = r*mult+q;
        System.out.println(ans);
  /// not fully undersoot ----> keep try to understand......
    }
}
