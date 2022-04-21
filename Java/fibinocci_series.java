import java.util.Scanner;

class fibinocci_series {
    static int fib(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        return (fib(n-1) + fib(n-2));
    }

    public static void main(String[] args) {
        int num;
        System.out.println("Enter which element of Fibinocci series you want to print: ");
        try (Scanner in = new Scanner(System.in)) {
            num = in.nextInt();
        }
        System.out.println("The number is: " + fib(num));
    }
}