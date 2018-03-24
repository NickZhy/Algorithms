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
public:
    void dfs(TreeNode* root, vector<int>& rst) {
        if(!root) return;
        dfs(root -> left, rst);
        rst.push_back(root -> val);
        dfs(root -> right, rst);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rst;
        dfs(root, rst);
        return rst;
    }
};