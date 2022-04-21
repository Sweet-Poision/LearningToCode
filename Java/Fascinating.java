
public class Fascinating {
    static boolean isFascinating(int number) {
        int[] arr = {0,0,0,0,0,0,0,0,0};
        int multipleOfTwo = number * 2;
        int multipleofThree = number * 3;
        while(multipleOfTwo > 0) {
            arr[multipleOfTwo%10]++;
            multipleOfTwo /= 10;
        }
        while(multipleofThree > 0) {
            arr[multipleofThree%10]++;
            multipleofThree /= 10;
        }
        for( int x : arr) {
            if(x < 1 || x > 1) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        int number;
        System.out.println("Give a number to check if it's a fascinating number or not: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            number = in.nextInt();
        }    
        if(isFascinating(number)) System.out.println("The number is a Fascinating number.");
        else System.out.println("The number is not a Fascinating number.");
    }
}