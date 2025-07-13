package coding.Queueinjava;
public class queueusingLL 
{
    public static class queue{
        public class node{
            int data;
            node next;
            node(int data1)
            {
                this.data=data1;
                this.next=null;
            }
        };
        node start=null;
        node end=null;
        int size=0;
        public void push(int x)
        {
            node temp=new node(x);
            if(start==null)
            {
                start=end=temp;
            }
            else{
                end.next=temp;
                end = temp;
            }
            size++;
        }
        public int pop()
        {
            if(start==null)
            {
                return -1;
            }
            node temp=start;
            start=start.next;
            size--;
            return temp.data;
        }
        public int peek()
        {
            if(start==null)
            {
                return -1;
            }
            return start.data;
        }
        public int sizes()
        {
            return size;
        }
    }
    public static void main(String[] args) {
        queue q=new queue();
        q.push(7);
        q.push(2);
        q.push(3);
        q.push(1);
        System.out.println("poped el:-"+q.pop());
        System.out.println("top el:-"+q.peek());
        System.out.println("size el:-"+q.sizes());
    } 
}
