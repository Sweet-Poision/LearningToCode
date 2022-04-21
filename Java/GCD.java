public class GCD {
    static void printGCD(int numa, int numb) {
        for(int i = 2; numa > 1 && numb > 1; i++) {
            if(numa % i == 0 && numb % i == 0 ) {
                while(numa%i==0 && numb%i==0) {
                    System.out.print(i + " ");
                    numa /= i;
                    numb /= i;
                }
            }
        }
    }
    public static void main(String[] args) {
        int numa, numb;
        try(java.util.Scanner input = new java.util.Scanner(System.in)) {
            System.out.println("Give first number: ");
            numa = input.nextInt();
            System.out.println("Give second number: ");
            numb = input.nextInt();
        }
        printGCD(numa, numb);

    }
}
