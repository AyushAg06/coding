// Base class Book
class Book {
    // Common attributes for all books
    private String title;
    private String author;
    private double price;

    // Constructor for Book class
    public Book(String title, String author, double price) {
        this.title = title;
        this.author = author;
        this.price = price;
    }

    // Method to display book details (to be overridden by subclasses)
    public void displayDetails() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
    }
}

// Derived class Fiction
class Fiction extends Book {
    // Constructor for Fiction class
    public Fiction(String title, String author, double price) {
        super(title, author, price); // Call the constructor of the Book class
    }

    // Method to display details specific to Fiction
    @Override
    public void displayDetails() {
        System.out.println("Fiction Book Details:");
        super.displayDetails();
    }
}

// Derived class NonFiction
class NonFiction extends Book {
    // Constructor for NonFiction class
    public NonFiction(String title, String author, double price) {
        super(title, author, price); // Call the constructor of the Book class
    }

    // Method to display details specific to NonFiction
    @Override
    public void displayDetails() {
        System.out.println("Non-Fiction Book Details:");
        super.displayDetails();
    }
}

public class LibraryManagementSystem {
    public static void main(String[] args) {
        // Create Fiction book object
        Fiction fictionBook = new Fiction("Harry Potter", "J.K. Rowling", 500);
        // Create Non-Fiction book object
        NonFiction nonFictionBook = new NonFiction("Sapiens", "Yuval Noah Harari", 700);

        // Display details of the Fiction book
        fictionBook.displayDetails();
        System.out.println();

        // Display details of the Non-Fiction book
        nonFictionBook.displayDetails();
    }
}
