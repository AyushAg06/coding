import java.util.Scanner;
public class CreditCardPaymentSystem 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        double creditLimit = 1000.00;  
        double balance = 0.00;
        try 
        {
            System.out.print("Enter your 16-digit credit card number: ");
            String cardNumber = scanner.nextLine();
            if (cardNumber.length() != 16) {
                throw new Exception("Invalid card number");
            }
            System.out.print("Enter payment amount: ");
            double paymentAmount = scanner.nextDouble();
            if (paymentAmount > (creditLimit - balance)) {
                throw new Exception("Insufficient credit limit");
            }
            balance += paymentAmount;
            System.out.println("Payment successful! balance is: " + balance);
        } catch (Exception e) 
        {
            System.out.println("Error: ");
        } finally 
        {
            System.out.println("Remaining credit limit: " + (creditLimit - balance));
        }
        scanner.close();
    }
}
