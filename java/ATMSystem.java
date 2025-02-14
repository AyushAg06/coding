import java.util.Scanner;

public class ATMSystem {
    private static final int CORRECT_PIN = 1234;
    private static double accountBalance = 3000.0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            // Ask user to enter their PIN
            System.out.print("Enter PIN: ");
            int enteredPin = Integer.parseInt(scanner.nextLine());

            // Validate PIN
            if (enteredPin != CORRECT_PIN) {
                throw new SecurityException("Error: Invalid PIN.");
            }

            // Ask for the withdrawal amount
            System.out.print("Withdraw Amount: ");
            double withdrawAmount = Double.parseDouble(scanner.nextLine());

            // Check if balance is sufficient
            if (withdrawAmount > accountBalance) {
                throw new IllegalArgumentException("Error: Insufficient balance.");
            }

            // Perform withdrawal
            accountBalance -= withdrawAmount;
            System.out.println("Withdrawal successful. New Balance: " + accountBalance);
        } catch (NumberFormatException e) {
            System.out.println("Error: Please enter a valid number.");
        } catch (SecurityException | IllegalArgumentException e) {
            System.out.println(e.getMessage());
        } finally {
            // Display the balance at the end, regardless of errors
            System.out.println("Current Balance: " + accountBalance);
            scanner.close();
        }
    }
}

