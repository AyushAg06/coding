public class rotateLL
{
    public static class node
    {
        public  
            int data;
            node next;
        public
            node(int data1)
            {
                this.data=data1;
                this.next=null;
            }

    };
    public static node array2LL(int[]arr)
    {
        node head=new node(arr[0]);
        node prev=head;
        for(int i=1;i<arr.length;i++)
        {
            node newnode=new node(arr[i]);
            prev.next=newnode;
            prev=newnode;
        }
        return head;
    }
    public static node rotatetheLL(node head,int k)
    {
        node tail=head;
        int len=1;
        while(tail.next!=null)
        {
            len++;
            tail=tail.next;
        }
        if(k%len==0)
            return head;
        k=k%len;
        tail.next=head;
        int num=len-k;
        node prev=null;;
        while(num>0)
        {
            prev=head;
            head=head.next;
            num--;
        }
        prev.next=null;
        return head;
    }
    public static void main(String[] args) {
        int[]arr=new int[]{1,2,3,4,5};
        int k=2;
        node head=array2LL(arr);
        head=rotatetheLL(head,k);
        node temp=head;
        while(temp!=null)
        {
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }
}


