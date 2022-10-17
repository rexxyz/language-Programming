public class ArrayInsertion {
    public static void main(String[] args) {
        int [] arr = {1,2,4,5,6};
        arr[2]=60;
        for(int i=0; i<arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println(arr.length);

    }
}
