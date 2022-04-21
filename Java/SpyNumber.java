public class SpyNumber {
    static boolean isSpy(int number) {
        int sum = 0, product = 1;
        while(number > 0) {
            sum += number % 10;
            product *= number % 10;
            number /= 10;
        }
        if(sum == product) return true;
        return false;
    }   
    public static void main(String[] args) {
        int num;
        System.out.println("Give a number to check if it's a Spy Number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            num = in.nextInt();
        }
        if(isSpy(num)) System.out.println("The number is a Spy Number");
        else System.out.println("The number is not a spy number");
    }
}
