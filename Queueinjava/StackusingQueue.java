// package coding.Queueinjava;
import java.util.*;
public class StackusingQueue 
{
    public static class stack
    {
        Queue<Integer>q=new LinkedList<>();
        public void push(int x)
        {
            q.add(x);
            for(int i=0;i<q.size()-1;i++)
            {
                q.add(q.remove());
            }
        }
        public int pop()
        {
            return q.remove();
        }
        public int top()
        {
            return q.peek();
        }
        public int size()
        {
            return q.size();
        }
    };
    public static void main(String[] args) {
        stack s=new stack();
         s.push(3);
        s.push(2);
        s.push(4);
        s.push(1);
        System.out.println("Top of the stack: " + s.top());
        System.out.println("Size of the stack before removing element: " + s.size());
        System.out.println("The deleted element is: " + s.pop());
        System.out.println("Top of the stack after removing element: " + s.top());
        System.out.println("Size of the stack after removing element: " + s.size());
    }
}
