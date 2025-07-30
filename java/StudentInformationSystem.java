// Abstract class Person
abstract class Person {
    // Common attributes for both students and teachers
    protected String name;
    protected int age;

    // Constructor for Person class
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Abstract method to be overridden by derived classes
    public abstract void displayDetails();
}

// Derived class Student
class Student extends Person {
    // Unique attribute for Student
    private int rollNumber;

    // Constructor for Student class
    public Student(String name, int age, int rollNumber) {
        super(name, age); // Call the constructor of the Person class
        this.rollNumber = rollNumber;
    }

    // Override displayDetails method to display student details
    @Override
    public void displayDetails() {
        System.out.println("Student Details:");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Roll Number: " + rollNumber);
    }
}

// Derived class Teacher
class Teacher extends Person {
    // Unique attribute for Teacher
    private String subject;

    // Constructor for Teacher class
    public Teacher(String name, int age, String subject) {
        super(name, age); // Call the constructor of the Person class
        this.subject = subject;
    }

    // Override displayDetails method to display teacher details
    @Override
    public void displayDetails() {
        System.out.println("Teacher Details:");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Subject: " + subject);
    }
}

public class StudentInformationSystem {
    public static void main(String[] args) {
        // Create a Student object
        Student student = new Student("Alice", 20, 101);
        // Create a Teacher object
        Teacher teacher = new Teacher("Mr. Smith", 40, "Mathematics");

        // Display details of the Student
        student.displayDetails();
        System.out.println();

        // Display details of the Teacher
        teacher.displayDetails();
    }
}

