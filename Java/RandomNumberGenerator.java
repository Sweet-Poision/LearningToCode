import java.lang.Math;
public class RandomNumberGenerator {
    static double generateRandomNumber(long first, long last) {
        return ((Math.random() % (last-first)) + first);
    }
    public static void main(String[] args) {
        String message1 = "Give lower limit of the random number";
        String message2 = "Give upper limit of the random number";
        long lowerLimit, upperLimit;
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            System.out.print(message1 + ": ");
            lowerLimit = in.nextLong();
            System.out.print(message2 + ": ");
            upperLimit = in.nextLong();
        }
        System.out.println(generateRandomNumber(lowerLimit, upperLimit));
    }
}
