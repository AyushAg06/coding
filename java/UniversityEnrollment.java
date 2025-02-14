import java.util.Scanner;
// Custom Exception for Course Full
class CourseFullException extends Exception {
    public CourseFullException(String message) {
        super(message);
    }
}
// Custom Exception for Prerequisite Not Met
class PrerequisiteNotMetException extends Exception {
    public PrerequisiteNotMetException(String message) {
        super(message);
    }
}
// Course class with course information
class Course {
    private String courseName;
    private int maxStudents;
    private int enrolledStudents;
    private String prerequisite;

    public Course(String courseName, int maxStudents, String prerequisite) {
        this.courseName = courseName;
        this.maxStudents = maxStudents;
        this.enrolledStudents = 0;
        this.prerequisite = prerequisite;
    }
    public String getCourseName() {
        return courseName;
    }
    public String getPrerequisite() {
        return prerequisite;
    }
    public void enroll() throws CourseFullException {
        if (enrolledStudents >= maxStudents) {
            throw new CourseFullException("Error: CourseFullException - " + courseName + " is full.");
        }
        enrolledStudents++;
    }
}
// Student class with enrollment logic
class Student {
    private String Studentname;
    private boolean hasCompletedPrerequisite;

    public Student(String name, boolean hasCompletedPrerequisite) {
        this.Studentname = name;
        this.hasCompletedPrerequisite = hasCompletedPrerequisite;
    }

    public void enrollInCourse(Course course) throws PrerequisiteNotMetException, CourseFullException {
        if (!hasCompletedPrerequisite && course.getPrerequisite() != null) {
            throw new PrerequisiteNotMetException(
                "Error: PrerequisiteNotMetException - Complete " + course.getPrerequisite() + " before enrolling in " + course.getCourseName() + "."
            );
        }
        course.enroll();
        System.out.println(Studentname + " successfully enrolled in " + course.getCourseName());
    }
}

public class UniversityEnrollment {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create sample courses
        Course coreJava = new Course("Core Java", 2, null);
        Course advancedJava = new Course("Advanced Java", 2, "Core Java");

        // Create a sample student
        System.out.print("Has the student completed Core Java? (yes/no): ");
        String prerequisiteStatus = scanner.nextLine();
        boolean hasCompletedCoreJava = prerequisiteStatus.equalsIgnoreCase("yes");

        Student student = new Student("John Doe", hasCompletedCoreJava);

        // Simulate enrollment
        try {
            System.out.print("Enroll in Course: ");
            String courseName = scanner.nextLine();

            if (courseName.equalsIgnoreCase("Advanced Java")) {
                student.enrollInCourse(advancedJava);
            } else if (courseName.equalsIgnoreCase("Core Java")) {
                student.enrollInCourse(coreJava);
            } else {
                System.out.println("Error: Course not available.");
            }
        } catch (PrerequisiteNotMetException | CourseFullException e) {
            System.out.println(e.getMessage());
        } finally {
            System.out.println("Enrollment process completed.");
        }

        scanner.close();
    }
}

