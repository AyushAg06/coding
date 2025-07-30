public class deletethekeys
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
    public static node convertarr2DLL(int arr[])
    {
        node head=new node(arr[0]);
        node prev=head;
        for(int i=1;i<arr.length;i++)
        {
            node newnode=new node(arr[i]);
            prev.next=newnode;
            newnode.back=prev;
            prev=newnode;
        }
        return head;
    }
    public static void print(node head)
    {
        while(head!=null)
        {
            System.out.print(head.data+"->");
            head=head.next;
        }
        System.out.println("NULL");
    }
    public static node deletethekeyvalues(node head,int k)
    {
        node temp=head;
        while(temp!=null)
        {
            if(temp.data==k)
            {
                if(head==temp)
                {
                    head=head.next;
                }
                node nextnode=temp.next;
                node prevnode=temp.back;
                if(nextnode!=null)
                {
                    nextnode.back=prevnode;
                }
                if(prevnode!=null)
                {
                    prevnode.next=nextnode;
                }
                temp=nextnode;
            }
            else{
                temp=temp.next;
            }

        }
        return head;
    }
    public static void main(String args[])
    {
        int[] arr=new int[]{10,4,10,10,6,10};
        int k=10;
        node head=convertarr2DLL(arr);
        head=deletethekeyvalues(head, k);
        print(head);
    }

}