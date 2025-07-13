package coding.Stackinjava;
public class stackusingLL 
{
    public static class stack{
        public class node
        {
            int data;
            node next;
            node(int data1)
            {
                this.data=data1;
                this.next=null;
            }
        };
        public node top=null;
        public int size=0;
        public void push(int x)
        {
            node newnode=new node(x);
            newnode.next=top;
            top=newnode;
            size++;
        }
        public int pop()
        {
            if(top==null)
            {
                return -1;
            }
            int topdata=top.data;
            top=top.next;
            size--;
            return topdata;
        }
        public int peek()
        {
            return top.data;
        }
        public int size()
        {
            return size;
        }
    };
    public static void main(String[] args) {
        stack s=new stack();
        s.push(2);
        s.push(4);
        s.push(6);
        System.out.println("Element popped " + s.pop());
        System.out.println("Stack size: " + s.size());
        System.out.println("Stack top: " + s.peek());
    }
}
