import java.util.*;
class Card {
    private String rank;
    private String symbol;
    // Constructor to initialize a card with rank and symbol
    public Card(String rank, String symbol) {
        this.rank = rank;
        this.symbol = symbol;
    }
    // Getters for rank and symbol
    public String getRank() {
        return rank;
    }
    public String getSymbol() {
        return symbol;
    }
    // Override toString method for a better display of card information
    @Override
    public String toString() {
        return rank + " of " + symbol;
    }
}
public class CardCollection {
    public static void main(String[] args) {
        // Create a collection to store cards (ArrayList implements the Collection interface)
        List<Card> cardList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        while (true) {
            // Display menu options to the user
            System.out.println("Choose an option:");
            System.out.println("1. Add Card");
            System.out.println("2. Search by Symbol");
            System.out.println("3. Display All Cards");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine();  // To consume newline character
            switch (choice) {
                case 1:
                    // Add card
                    System.out.print("Enter Symbol (Hearts, Diamonds, etc.): ");
                    String symbol = scanner.nextLine();
                    System.out.print("Enter Rank (Ace, 2, King, etc.): ");
                    String rank = scanner.nextLine();
                    Card card = new Card(rank, symbol);
                    cardList.add(card);
                    System.out.println("Card added successfully!\n");
                    break;
                case 2:
                    // Search cards by symbol
                    System.out.print("Enter Symbol to search: ");
                    String searchSymbol = scanner.nextLine();
                    boolean found = false;
                    for (Card c : cardList) {
                        if (c.getSymbol().equalsIgnoreCase(searchSymbol)) {
                            System.out.println(c);
                            found = true;
                        }
                    }
                    if (!found) {
                        System.out.println("No cards found with the symbol: " + searchSymbol);
                    }
                    System.out.println();
                    break;
                case 3:
                    // Display all cards
                    if (cardList.isEmpty()) {
                        System.out.println("No cards stored.");
                    } else {
                        System.out.println("Displaying all stored cards:");
                        for (Card c : cardList) {
                            System.out.println(c);
                        }
                    }
                    System.out.println();
                    break;
                case 4:
                    // Exit the program
                    System.out.println("Exiting program...");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.\n");
            }
        }
    }
}

