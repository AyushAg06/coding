public class pairofsum
{
    public static class node{
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
    public static node array2ll(int[]arr)
    {
        node head =new node(arr[0]);
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
    public static void FindSum(node head,int sum)
    {
        node temp1=head;
        while(temp1!=null)
        {
            node temp2=temp1.next;
            while(temp2!=null && temp1.data+temp2.data<=sum)
            {
                if(temp1.data+temp2.data==sum)
                {
                    System.out.println("("+temp1.data+","+temp2.data+")");
                }
                temp2=temp2.next;
            }
            temp1=temp1.next;
        }

    } 
    public static void main(String[] args) {
        int arr[]=new int[]{1,2,3,4,8};
        int sum=5;
        node head=array2ll(arr);
        FindSum(head,sum);
    }

}
