import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
class TicketBookingSystem 
{
    private final boolean[] seats;
    private final Lock seatLock;
    public TicketBookingSystem(int numSeats) 
    {
        seats = new boolean[numSeats];
        seatLock = new ReentrantLock();
    }
    public void bookSeat(String customerType, int seatNumber) {
        seatLock.lock();
        try 
        {
            if (seatNumber < 0 || seatNumber >= seats.length) 
            {
                System.out.println(customerType + " Error: Invalid seat number " + seatNumber);
                return;
            }
            if (!seats[seatNumber]) 
            {
                seats[seatNumber] = true;
                System.out.println(customerType + " Booking: Seat " + seatNumber + " confirmed.");
            } else {
                System.out.println(customerType + " Error: Seat " + seatNumber + " already booked.");
            }
        } finally {
            seatLock.unlock();
        }
    }
}
class Customer extends Thread {
    private final TicketBookingSystem bookingSystem;
    private final int seatNumber;
    private final String customerType;
    public Customer(TicketBookingSystem bookingSystem, int seatNumber, String customerType, int priority) {
        this.bookingSystem = bookingSystem;
        this.seatNumber = seatNumber;
        this.customerType = customerType;
        setPriority(priority);
    }
    @Override
    public void run() {
        bookingSystem.bookSeat(customerType, seatNumber);  // Attempt to book a seat
    }
}
public class MultiThreadedTicketBookingSystem {
    public static void main(String[] args) {
        int totalSeats = 5; 
        TicketBookingSystem bookingSystem = new TicketBookingSystem(totalSeats);
        Customer vip1 = new Customer(bookingSystem, 1, "VIP", Thread.MAX_PRIORITY);
        Customer regular1 = new Customer(bookingSystem, 1, "Regular", Thread.NORM_PRIORITY);  // Try to book the same seat as VIP
        Customer regular2 = new Customer(bookingSystem, 2, "Regular", Thread.NORM_PRIORITY);
        Customer vip2 = new Customer(bookingSystem, 3, "VIP", Thread.MAX_PRIORITY);
        vip1.start();
        regular1.start();
        regular2.start();
        vip2.start();
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

