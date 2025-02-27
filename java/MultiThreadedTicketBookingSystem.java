import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class TicketBookingSystem {
    private final boolean[] seats;  // Seats array, true if booked, false otherwise
    private final Lock seatLock;    // Lock to ensure synchronized booking

    public TicketBookingSystem(int numSeats) {
        seats = new boolean[numSeats];  // Initialize all seats to be available
        seatLock = new ReentrantLock(); // Reentrant lock for synchronization
    }

    // Method to book a seat
    public void bookSeat(String customerType, int seatNumber) {
        seatLock.lock();  // Synchronize access to seats
        try {
            if (seatNumber < 0 || seatNumber >= seats.length) {
                System.out.println(customerType + " Error: Invalid seat number " + seatNumber);
                return;
            }
            if (!seats[seatNumber]) {  // If the seat is not yet booked
                seats[seatNumber] = true;  // Book the seat
                System.out.println(customerType + " Booking: Seat " + seatNumber + " confirmed.");
            } else {
                System.out.println(customerType + " Error: Seat " + seatNumber + " already booked.");
            }
        } finally {
            seatLock.unlock();  // Release the lock
        }
    }
}

// Class for Regular and VIP customers booking seats
class Customer extends Thread {
    private final TicketBookingSystem bookingSystem;
    private final int seatNumber;
    private final String customerType;

    public Customer(TicketBookingSystem bookingSystem, int seatNumber, String customerType, int priority) {
        this.bookingSystem = bookingSystem;
        this.seatNumber = seatNumber;
        this.customerType = customerType;
        setPriority(priority);  // Set thread priority
    }

    @Override
    public void run() {
        bookingSystem.bookSeat(customerType, seatNumber);  // Attempt to book a seat
    }
}

public class MultiThreadedTicketBookingSystem {
    public static void main(String[] args) {
        int totalSeats = 5;  // Example of 5 available seats
        TicketBookingSystem bookingSystem = new TicketBookingSystem(totalSeats);

        // Create regular and VIP customers
        Customer vip1 = new Customer(bookingSystem, 1, "VIP", Thread.MAX_PRIORITY);
        Customer regular1 = new Customer(bookingSystem, 1, "Regular", Thread.NORM_PRIORITY);  // Try to book the same seat as VIP
        Customer regular2 = new Customer(bookingSystem, 2, "Regular", Thread.NORM_PRIORITY);
        Customer vip2 = new Customer(bookingSystem, 3, "VIP", Thread.MAX_PRIORITY);

        // Start booking seats
        vip1.start();
        regular1.start();  // This thread should fail to book seat 1 as VIP has higher priority
        regular2.start();
        vip2.start();
        
        // Join threads to ensure all threads complete execution before the program exits
        try {
            vip1.join();
            regular1.join();
            regular2.join();
            vip2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

