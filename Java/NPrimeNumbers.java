public class NPrimeNumbers {
    static int size = 1000000;
    static int[] arr = new int[size];
    static void sieveOfErosthenes() {
        for(int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        for(int i = 2; i < size; i++) {
            if(arr[i] == 0) {
                for(int j = 2; j*i < size; j++) {
                    arr[j*i] = 1;
                }
            }
        }
    }
    public static void main(String[] args) {
        int number;
        System.out.println("Give limit upto which you want to print the prime numbers: ");
        try(java.util.Scanner input = new java.util.Scanner(System.in)) {
            number = input.nextInt();
        }
        sieveOfErosthenes();
        for(int i = 2; i <= number; i++) {
            if(arr[i] == 0) {
                System.out.print(i + " ");
            }
        }
    }
}
