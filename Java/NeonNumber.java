public class NeonNumber {
    static boolean isNeon(int number) {
        int square = number * number;
        int sum = 0;
        while(square > 0) {
            sum += square%10;
            square /= 10;
        }
        if(number == sum) return true;
        return false;
    }
    public static void main(String[] args) {
        int number;
        System.out.println("Give a number to check if it's a Neon Number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            number = in.nextInt();
        }
        if(isNeon(number)) System.out.println("The number is neon number.");
        else System.out.println("The number is not a neon number.");
    }
}
