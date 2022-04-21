public class ArmstrongNumber {
    static boolean isArmstrong(int num) {
        int length=0, temp = num;
        long sum = 0;
        while(temp > 0) {
            temp/=10;
            length++;
        }
        temp = num;
        while(temp > 0) {
            sum += Math.pow(temp%10,length);
            temp /= 10;
        }
        if(sum == num) return true;
        return false;
    }

    static void printArmstrongNumbers(int num) {
        for(int i = 1; i <= num; i++) {
            if(isArmstrong(i)) {
                System.out.println(i);
            }
        }
    }
    public static void main(String[] args) {
        int number;
        System.out.print("Give a limit upto which you want to print Armstrong number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            number = in.nextInt();
        }
        printArmstrongNumbers(number);
    }    
}