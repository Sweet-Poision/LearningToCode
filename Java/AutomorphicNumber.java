public class AutomorphicNumber {

    static boolean isAutomorphic(int num) {
        int square = num * num;
        while(num > 0) {
            if(num%10 != square%10) {
                return false;
            }
            num /= 10;
            square /= 10;
        }
        return true;
    }
    public static void main(String[] args) {
        int number;
        System.out.println("Give a number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            number = in.nextInt();
        }
        if(isAutomorphic(number)==true) System.out.println("It is Automorphic number.");
        else System.out.println("It isn't Automorphic number.");
    }
}
