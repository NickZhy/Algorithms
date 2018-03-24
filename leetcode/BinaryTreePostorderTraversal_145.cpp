/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, vector<int>& rst) {
        if(!root) return;
        dfs(root -> left, rst);
        dfs(root -> right, rst);
        rst.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> rst;
        dfs(root, rst);
        return rst;
    }
};