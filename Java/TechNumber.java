public class TechNumber {
    static int lengthOf(int num) {
        int length = 0;
        while(num > 0) {
            length++;
            num /= 10;
        }
        return length;
    }

    static boolean isTechNumber(int num) {
        int length = lengthOf(num);
        if(length % 2 != 0) return false;
        int num1 = (int) (num / (Math.pow(10,length/2)));
        int num2 = (int) (num % (Math.pow(10,length/2)));
        int sumOfHalves = num1 + num2;
        if(sumOfHalves * sumOfHalves == num) return true;
        return false;
    }
    public static void main(String[] args) {
        int number;
        System.out.println("Give a number to check if it's a Tech Number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            number = in.nextInt();
        }
        if(isTechNumber(number)) System.out.println("The number is Tech Number.");
        else System.out.println("The number is not a Tech Number.");
    }
}
