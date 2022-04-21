public class BitwiseSwap {
    public static void main(String[] args) {
        int numa, numb;
        java.util.Scanner input = new java.util.Scanner(System.in);
        numa = input.nextInt();
        numb = input.nextInt();
        numa = (numa ^ numb);
        numb = (numa ^ numb);
        numa = (numa ^ numb);
        System.out.println("a = " + numa + " b = " + numb);
    }
}
