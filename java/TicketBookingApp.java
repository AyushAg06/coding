class TicketCounter {
    private int availableSeats = 5;
    public synchronized void bookTicket(String name, int seatsRequested) {
        if (seatsRequested <= availableSeats) {
            System.out.println(name + " successfully booked " + seatsRequested + " seat(s).");
            availableSeats -= seatsRequested;
        } else {
            System.out.println(name + " failed to book. Not enough seats.");
        }
    }
}
class BookingTicket extends Thread {
    private TicketCounter counter;
    private String passengerName;
    private int seatsRequested;
    public BookingTicket(TicketCounter counter, String passengerName, int seatsRequested) {
        this.counter = counter;
        this.passengerName = passengerName;
        this.seatsRequested = seatsRequested;
    }
    @Override
    public void run() {
        counter.bookTicket(passengerName, seatsRequested);
    }
}
public class TicketBookingApp {
    public static void main(String[] args) {
        TicketCounter counter = new TicketCounter();
        BookingTicket t1=new BookingTicket(counter,"Raghav",2);
        BookingTicket t2=new BookingTicket(counter,"Harsh",1);
        BookingTicket t3=new BookingTicket(counter,"Ayush",3);
        t1.start();
        t2.start();
        t3.start();
    }
}
