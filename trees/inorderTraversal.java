/**
Finds the inorder traversal of a binary tree. Time complexity : O(N) N -> is the number of nodes. space complexity : O(N)

 */
class Solution {
    List<Integer> res = new ArrayList<>();
    private void inorderTraversalUtil(TreeNode root) {
        if (root == null)
            return;
        inorderTraversalUtil(root.left);
        res.add(root.val);
        inorderTraversalUtil(root.right);
    } 
    public List<Integer> inorderTraversal(TreeNode root) {
        inorderTraversalUtil(root);
        return res;
    }
}