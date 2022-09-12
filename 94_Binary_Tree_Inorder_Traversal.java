class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
    this.val = val;
    this.left = left;
    this.right = right;
    }
}

class Solution {
    public void trace(TreeNode Node, List<Integer> ret)
    {
        if(Node == null)
        {
            return;
        }
        trace(Node.left, ret);
        ret.add(Node.val);
        trace(Node.right, ret);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<Integer>();
        trace(root, ret);
        return ret;
    }
}

