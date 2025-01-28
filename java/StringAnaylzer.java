import java.util.Scanner;
public class StringAnaylzer
{   
        public static void main(String[] args) {
        // Create a scanner object to take input from the user
        Scanner scanner = new Scanner(System.in);

        // Prompt user to enter a string
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        // Initialize counters for vowels, consonants, digits, and special characters
        int vowelCount = 0;
        int consonantCount = 0;
        int digitCount = 0;
        int specialCharCount = 0;

        // Convert the input string to lowercase for easier comparison
        input = input.toLowerCase();

        // Loop through each character in the input string
        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);

            // Check if the character is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
            // Check if the character is a consonant (a letter but not a vowel)
            else if (ch >= 'a' && ch <= 'z') {
                consonantCount++;
            }
            // Check if the character is a digit
            else if (ch >= '0' && ch <= '9') {
                digitCount++;
            }
            // If it's not a letter or digit, it's a special character (including space)
            else {
                specialCharCount++;
            }
        }

        // Output the results
        System.out.println("Vowels: " + vowelCount);
        System.out.println("Consonants: " + consonantCount);
        System.out.println("Digits: " + digitCount);
        System.out.println("Special Characters: " + specialCharCount);

        // Close the scanner
        scanner.close();
    }
}
