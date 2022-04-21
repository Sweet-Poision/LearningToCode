public class PetersonNumber {
    static int[] factorialValues = {0,0,0,0,0,0,0,0,0};
    static int factorial(int num) {
        if(factorialValues[num] != 0) return factorialValues[num];
        if(num == 0) return 1;
        if(num == 1) return 1;
        return num * factorial(num-1);
    }

    static boolean isPetersonNumber(int number) {
        int sumOfFactorial = 0;
        int temp = number;
        while(temp > 0) {
            sumOfFactorial += factorial(temp%10);
            temp /= 10;
        }
        if(sumOfFactorial == number) return true;
        return false;
    }
    public static void main(String[] args) {
        int num;
        System.out.println("Give a number to check if it's a Peterson number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            num = in.nextInt();
        }
        if(isPetersonNumber(num)) System.out.println("Number is Peterson Number");
        else System.out.println("Number is not Peterson Number");
    }
}
