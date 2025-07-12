public class removeduplicatesfromDLL 
{
    public static class node
    {
        public  
            int data;
            node next;
            node back;
        public
            node(int data1)
            {
                this.data=data1;
                this.next=null;
                this.back=null;
            }

    };
    public static node array2LL(int[]arr)
    {
        node head=new node(arr[0]);
        node prev=head;
        for(int i=1;i<arr.length;i++)
        {
            node newnode=new node(arr[i]);
            newnode.back=prev;
            prev.next=newnode;
            prev=newnode;
        }
        return head;
    }
    public static node removeduplicates(node head)
    {
        node temp=head;
        while(temp!=null && temp.next!=null)
        {
            node newnode=temp.next;
            while(newnode!=null && newnode.data==temp.data)
            {
                    newnode=newnode.next;
            }
            temp.next=newnode;
            if(newnode!=null)
            {
                newnode.back=temp;
            }
            temp=temp.next;
        }
        return head;
    }
    public static void main(String[] args) {
        int[]arr=new int[]{1,1,1,1,2,3,3,4};
        node head=array2LL(arr);
        head=removeduplicates(head);
        node temp=head;
        while(temp!=null)
        {
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }
}
