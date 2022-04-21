import java.util.Scanner;

class palindrome {
    static int reverse(int n) {
        int ans = 0;
        while(n>0) {
            ans += n%10;
            ans*=10;
            n/=10;
        }
        ans/=10;
        return ans;
    }    

    static boolean isPalindrome(int n) {
        int reversed = reverse(n);
        if(reversed == n) return true;
        return false;
    }

    public static void main(String[] args) {
        int number;
        System.out.print("Give a number to check if it's a palindrome: ");
        try(Scanner in = new Scanner(System.in)) {
            number = in.nextInt();
        }
        if(isPalindrome(number)) 
            System.out.println(number + " is a palindrome.");
        else
            System.out.println(number + " is not a palindrome.");
    }
}
