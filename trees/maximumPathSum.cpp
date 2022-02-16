/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int solve_it(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        if (root -> left == NULL && root -> right == NULL) {
            ans = max(ans, root -> val);
            return root -> val;
        }
        
        int left_sum = solve_it(root -> left);
        int right_sum = solve_it(root -> right);
        
        int max_sum_with_root = max( {root -> val, root -> val + left_sum, root -> val + right_sum});
        
        ans = max({ans, max_sum_with_root, root -> val + left_sum + right_sum});
        
        return max_sum_with_root;
    }
    int maxPathSum(TreeNode* root) {
        
        
        solve_it(root);
        return ans;
        
    }
};