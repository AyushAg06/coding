package coding.Queueinjava;
public class queueusingarray
{
    public static class queue
    {
        int size=10;
        int curr_size=0;
        int start=-1,end=-1;
        int arr[]=new int[size];
        void push(int x)
        {
            if(curr_size==size)
            {
                System.out.println("Queue is full\nExiting...");
                System.exit(1);
            }
            if(end==-1)
            {
                start=0;
                end=0;
            }
            else{
                end=(end+1)%size;
            }
            arr[end]=x;
            System.out.println("the element pushed is:-"+x);
            curr_size++;
        }
        int pop()
        {
            if(start==-1)
            {
                System.out.println("Queue Empty\nExiting...");
                System.exit(1);
            }
            int popel=arr[start];
            if(curr_size==1)
            {
                start=-1;
                end=-1;
            }
            else
            {
                start=(start+1)%size;
            }
            curr_size--;
            return popel;
        }
        int peek()
        {
            if(start==-1)
            {
                System.out.println("Queue is empty");
                System.exit(1);
            }
            return arr[start];
        }
        int size()
        {
            return curr_size;
        }
    };
    public static void main(String[] args) {
        queue q=new queue();
        q.push(4);
        q.push(6);
        q.push(2);
        System.out.println("The peek of the queue before deleting any element " + q.peek());
        System.out.println("The size of the queue before deletion " + q.size());
        System.out.println("The first element to be deleted " + q.pop());
        System.out.println("The peek of the queue after deleting an element " + q.peek());
        System.out.println("The size of the queue after deleting an element " + q.size());
    }
}
