/**
Finds the preorder traversal of a binary tree. Time complexity : O(N) N -> is the number of nodes. space complexity : O(N)

 */
class Solution {
    List<Integer> res = new ArrayList<>();
    private void preorderTraversalUtil(TreeNode root) {
        if (root == null)
            return;
        
        res.add(root.val);
        preorderTraversalUtil(root.left);
        preorderTraversalUtil(root.right);
    } 
    public List<Integer> preorderTraversal(TreeNode root) {
        preorderTraversalUtil(root);
        return res;
    }
}