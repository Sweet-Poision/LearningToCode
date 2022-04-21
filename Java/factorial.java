import java.util.Scanner;

class factorial {
    static long factorialOf(long n) {
        if(n==0) return 1;
        if(n==1) return 1;
        return (n * factorialOf(n-1));
    } 

    public static void main(String[] args) {
        long number;
        System.out.print("Give a number to calculate it's factorial: ");
        try(Scanner in = new Scanner(System.in)) {
            number = in.nextLong();
        }
        System.out.println("Factorial of " + number + " is " + factorialOf(number));
    }
}
