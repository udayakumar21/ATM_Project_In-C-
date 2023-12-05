import java.util.Scanner;

class ATM {
    private long accountNo;
    private String name;
    private int PIN;
    private double balance;
    private String mobileNo;

    public void setData(long accountNo_a, String name_a, int PIN_a, double balance_a, String mobileNo_a) {
        accountNo = accountNo_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobileNo = mobileNo_a;
    }

    public long getAccountNo() {
        return accountNo;
    }

    public String getName() {
        return name;
    }

    public int getPIN() {
        return PIN;
    }

    public double getBalance() {
        return balance;
    }

    public String getMobileNo() {
        return mobileNo;
    }

    public void setMobile(String mob_prev, String mob_new) {
        if (mob_prev.equals(mobileNo)) {
            mobileNo = mob_new;
            System.out.println("\nSuccessfully Updated Mobile no.");
        } else {
            System.out.println("\nIncorrect !!! Old Mobile no");
        }
    }

    public void cashWithdraw(int amount_a) {
        if (amount_a > 0 && amount_a < balance) {
            balance -= amount_a;
            System.out.println("\nPlease Collect Your Cash");
            System.out.println("Available Balance: " + balance);
        } else {
            System.out.println("\nInvalid Input or Insufficient Balance");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int choice, enterPIN;
        long enterAccountNo;

        Scanner scanner = new Scanner(System.in);
        ATM user1 = new ATM();
        user1.setData(404402, "User", 1111, 45000.90, "8867983747");

        do {
            System.out.println("\n****Welcome to ATM*****");
            System.out.println("Enter Your Account No: ");
            enterAccountNo = scanner.nextLong();

            System.out.println("Enter PIN: ");
            enterPIN = scanner.nextInt();

            if (enterAccountNo == user1.getAccountNo() && enterPIN == user1.getPIN()) {
                do {
                    int amount = 0;
                    String oldMobileNo, newMobileNo;

                    System.out.println("\n**** Welcome to ATM *****");
                    System.out.println("Select Options ");
                    System.out.println("1. Check Balance");
                    System.out.println("2. Cash withdraw");
                    System.out.println("3. Show User Details");
                    System.out.println("4. Update Mobile no.");
                    System.out.println("5. Exit");
                    choice = scanner.nextInt();

                    switch (choice) {
                        case 1:
                            System.out.println("\nYour Bank balance is: " + user1.getBalance());
                            break;

                        case 2:
                            System.out.println("\nEnter the amount: ");
                            amount = scanner.nextInt();
                            user1.cashWithdraw(amount);
                            break;

                        case 3:
                            System.out.println("\n*** User Details are: ");
                            System.out.println("-> Account no: " + user1.getAccountNo());
                            System.out.println("-> Name: " + user1.getName());
                            System.out.println("-> Balance: " + user1.getBalance());
                            System.out.println("-> Mobile No.: " + user1.getMobileNo());
                            break;

                        case 4:
                            System.out.println("\nEnter Old Mobile No.: ");
                            oldMobileNo = scanner.next();

                            System.out.println("Enter New Mobile No.: ");
                            newMobileNo = scanner.next();

                            user1.setMobile(oldMobileNo, newMobileNo);
                            break;

                        case 5:
                            System.exit(0);

                        default:
                            System.out.println("\nEnter Valid Data !!!");
                            break;
                    }

                } while (true);
            } else {
                System.out.println("\nUser Details are Invalid !!!");
            }
        } while (true);
    }
}
