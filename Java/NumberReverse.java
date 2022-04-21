class NumberReverse {
    static int reverseOfNumber(int num) {
        int ans = 0;
        while(num > 0) {
            ans += (num%10);
            ans *= 10;
            num /= 10;
        }
        ans /= 10;
        return ans;
    }
    public static void main(String[] args) {
        int num;
        System.out.print("Give a number to reverse the number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            num = in.nextInt();
        }
        System.out.println(reverseOfNumber(num));
    }
}