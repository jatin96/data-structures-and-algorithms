
/** 
This program finds the level order traversal of a binary tree. Time complexity : O(n).
*/
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        queue.add(root);
        
        if (root == null)
            return Arrays.asList();
        
        while (!queue.isEmpty()) {   
            int n = queue.size();
            List<Integer> tmp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode node = queue.peek();
                queue.remove();
                tmp.add(node.val);
                if(node.left != null)
                queue.add(node.left);
                if(node.right != null)
                queue.add(node.right);
            }
            
            res.add(tmp);
        }
        
        return res;
    }
}