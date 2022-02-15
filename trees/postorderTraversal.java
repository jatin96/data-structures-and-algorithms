/**
Finds the postorder traversal of a binary tree. Time complexity : O(N) N -> is the number of nodes. space complexity : O(N)

 */
class Solution {
    List<Integer> res = new ArrayList<>();
    private void postorderTraversalUtil(TreeNode root) {
        if (root == null)
            return;
        
        postorderTraversalUtil(root.left);
        postorderTraversalUtil(root.right);
        res.add(root.val);
    } 
    public List<Integer> postorderTraversal(TreeNode root) {
        postorderTraversalUtil(root);
        return res;
    }
}