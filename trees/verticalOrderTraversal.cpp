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
    map<int, vector<pair<int, int>>> mm;
    void solveIt(TreeNode *root, int row, int col) {
        if (root == NULL)
            return ;
        // by default
        mm[col].push_back({row, root -> val});
        
        solveIt(root -> left, row + 1, col - 1);
        solveIt(root -> right, row + 1, col + 1);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        solveIt(root, 0, 0);
        
        vector<vector<int>> res;
        for(auto it = mm.begin(); it != mm.end(); it++) {
            auto col_vector = it -> second;
            sort(col_vector.begin(), col_vector.end());
            vector<int> tmp;
            for(auto col_item: col_vector)
                tmp.push_back(col_item.second);
            
            res.push_back(tmp);
        }
        
        return res;
        
    }
};