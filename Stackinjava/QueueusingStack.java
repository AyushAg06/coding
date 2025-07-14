package coding.Stackinjava;
import java.util.*;
public class QueueusingStack 
{
    public static class queue
    {
        Stack<Integer> s1;
        Stack<Integer> s2;
        public queue()
        {
            s1=new Stack<>();
            s2=new Stack<>();
        }
        public void push(int x)
        {
            while(s1.size()>0)
            {
                s2.push(s1.pop());
            }
            s1.push(x);
            while(s2.size()>0)
            {
                s1.push(s2.pop());
            }
        }
        public int pop()
        {
            return s1.pop();
        }
        public int top()
        {
            return s1.peek();
        }
        public boolean empty()
        {
            return s1.isEmpty();
        }
    }
    public static void main(String[] args) {
        queue q=new queue();
        q.push(3);
        q.push(4);
        System.out.println("The element poped is " + q.pop());
        q.push(5);
        System.out.println("The top element is " + q.top());
        System.out.println("The size of the queue is " + q.empty());
    }

}
