public class SunnyNumber {
    static boolean isSunnyNumber(int num) {
        num++;
        if(Math.pow(Math.sqrt(num),2) == num) return true;
        return false;
    }
    public static void main(String[] args) {
        int number; 
        System.out.println("Give a number to check if it's a Sunny number or not:");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            number = in.nextInt();
        }
        if(isSunnyNumber(number)) System.out.println("The number is Sunny Number");
        else System.out.println("The number is not a Sunny Number");
    }
}
