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
    void dfs(TreeNode* root, int depth, int& minDep) {
        if(!root) return;
        if(depth > minDep) return;
        if(!root -> right && !root -> left) minDep = depth;
        dfs(root -> left, depth + 1, minDep);
        dfs(root -> right, depth + 1, minDep);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int depth = 1, minDep = INT_MAX;
        dfs(root, depth, minDep);
        return minDep;
    }
};