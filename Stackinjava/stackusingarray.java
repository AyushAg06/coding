package coding.Stackinjava;
// import java.util.*;
public class stackusingarray 
{
    public static class stack
    {
        int size=10;
        int arr[]=new int[10];
        int top=-1;
        void push(int x)
        {
             if (top + 1 >= size) {
                System.out.println("Stack Overflow");
                return;
             }
            top=top+1;
            arr[top]=x;
        }
        int pop()
        {
            int x=arr[top];
            top=top-1;
            return x;
        }
        int peek()
        {
            return arr[top];
        }
        int size()
        {
            return top+1;
        }
    };
    public static void main(String args[])
    {
        stack s=new stack();
        s.push(2);
        s.push(3);
        s.push(4);
        System.out.println("The top :-"+s.peek());
        System.out.println("The size :-"+s.size());
        System.out.println("The delete element :-"+s.pop());
        System.out.println("The top after pop:-"+s.peek());
        System.out.println("The top after pop:-"+s.size());
    }
}

