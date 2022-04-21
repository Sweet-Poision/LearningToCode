class Bank {
    private int balance;
    java.util.Scanner input = new java.util.Scanner(System.in);
    Bank() {
        this.balance = 2000;
    }
    void getBalance() {
        System.out.println("Your remaining balance is: " + balance);
    }
    void withdraw() {
        int amountToWithdraw;
        System.out.println("Enter the amount to withdraw: ");
        amountToWithdraw = input.nextInt();
        if(balance >= amountToWithdraw) {
            System.out.println("Amount Withdrawn Successfull.");
            this.balance -= amountToWithdraw;
            this.getBalance();
            return;
        }
        System.out.println("Not Enough Balance.");
    }
    void deposit() {
        int depositAmount;
        System.out.println("Enter the amount to deposit");
        depositAmount = input.nextInt();
        this.balance += depositAmount;
        System.out.println("Amount deposited Successfully");
    }
}

public class ATM {
    public static void main(String[] args) {
        try (java.util.Scanner input = new java.util.Scanner(System.in)) {
            int answer;
            Bank myAccount = new Bank();
            while(true) {
                System.out.println("1.Check Balance\n2.Withdraw Money\n3.Deposit Money\n4.Exit");
                answer = input.nextInt();
                switch(answer) {
                    case 1:
                        myAccount.getBalance();
                        break;
                    case 2:
                        myAccount.withdraw();
                        break;
                    case 3:
                        myAccount.deposit();
                        break;
                    case 4:
                        System.exit(0);
                    default:
                        System.out.println("Invalid Option");
                }
            }
        }
        
    }
}
