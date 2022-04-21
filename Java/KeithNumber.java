public class KeithNumber {
    static int LengthOf(int number) {
        int length = 0;
        while(number > 0) {
            length++;
            number /= 10;
        }
        return length;
    }

    static int sumOf(int[] arr) {
        int sum = 0;
        for(int x : arr) {
            sum += x;
        }
        return sum;
    }

    static int keithNumber(int number, int n) {
        int length = LengthOf(number);
        int temp = number;
        int[] arr = new int[length];
        for(int i = 0; i < length; i++) {
            arr[i] = temp%10;
            temp /= 10;
        }
        if(n <= length) return arr[n-1];
        for(int i = 0; i < n - length; i++) {
            int sum = sumOf(arr);
            int tempValue;
            for(int j = 0; j < length; j++) {
                tempValue = arr[j];
                arr[j] = sum;
                sum = tempValue;
            }
        } 
        return arr[0];
    }

    public static void main(String[] args) {
        int number, n;
        System.out.println("Give a number: ");
        try(java.util.Scanner in = new java.util.Scanner(System.in)) {
            number = in.nextInt();
            System.out.println("Enter the value of n, which is the position of Keith Sequence.");
            n = in.nextInt();
        }
        System.out.println(keithNumber(number, n));
    }
}
