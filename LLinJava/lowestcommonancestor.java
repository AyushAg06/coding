public class lowestcommonancestor {
    public static class node 
    {
        public int data;
        public node left;
        public node right;

        node(int data1) 
        {
            this.data = data1;
        }
    }

    public static node commonancestor(node root, node p, node q) {
        if (root == null || root == p || root == q) {
            return root;
        }

        node left = commonancestor(root.left, p, q);
        node right = commonancestor(root.right, p, q);

        if (left == null) return right;
        if (right == null) return left;
        return root;
    }

    public static void main(String[] args) {
        node root = new node(1);
        root.left = new node(2);
        root.right = new node(3);
        root.left.left = new node(4);
        root.left.right = new node(5);
        root.right.right = new node(6);

        node p = root.left.left;   // node with data 4
        node q = root.left.right;  // node with data 5

        node ans = commonancestor(root, p, q);
        System.out.println(ans.data);  // ✅ Print the data value
    }
}


