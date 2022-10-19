import java.util.Scanner;
public class Bubbleshort {
    public static void main(String[] args) {
        int arr[];
        int temp;
        int n;
        Scanner sc= new Scanner(System.in);
        System.out.println("enter the number you want");
        n = sc.nextInt();
        arr = new int[n];
        for( int i=0; i<n;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("all entered value are :- ");
        for( int i=0; i<n;i++)
        {
            System.out.print(""+arr[i] + ";  ");
        }
        System.out.println();
        System.out.println("the length of array is :-  " +arr.length);
        int x= arr.length;
       // System.out.println(x);
        for (int i = 0; i < x; i++) {
            for (int j = i+1; j < x; j++) {
                if (arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
         }
            }
            System.out.print( arr[i]+";  ");
        }
    }
}
