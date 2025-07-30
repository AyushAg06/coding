class Product {
    // Attributes of the Product class
    private int id;
    private String name;
    private double price;

    // Constructor to initialize the Product object
    public Product(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    // Method to display the product details
    public void displayProductDetails() {
        System.out.println("Product Details:");
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Price: " + price);
    }
}

public class ProductDemo {
    public static void main(String[] args) {
        // Create a Product object using the constructor
        Product product = new Product(101, "Laptop", 75000);

        // Display the product details
        product.displayProductDetails();
    }
}

