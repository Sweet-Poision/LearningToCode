import java.util.Scanner;
import java.lang.Math;

class isPrime {
    static boolean is_prime(int n) {
        for(int i = 2; i <= Math.sqrt(n); ++i) {
            if(n%i==0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int number;
        System.out.print("Give a number to check if its a prime number or not: ");
        try(Scanner in = new Scanner(System.in)) {
            number = in.nextInt();
        }
        System.out.println((is_prime(number))?"Number is prime.":"Number is not prime.");
    }
}

