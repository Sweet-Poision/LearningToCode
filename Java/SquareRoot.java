public class SquareRoot {
    public static double squareRoot(int num) {
        double t;
        double sqrtroot = num / 2;
        do {
            t = sqrtroot;
            sqrtroot = (t + (num / t)) / 2;
        } while ((t - sqrtroot) != 0);
        return sqrtroot;
    }
    public static void main(String[] args) {
        int number;
        java.util.Scanner input = new java.util.Scanner(System.in);
        number = input.nextInt();
        System.out.println("Square Root of the number " + number + " is " + squareRoot(number));
    }
}
