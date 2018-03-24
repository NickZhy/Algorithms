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
    void dfs(TreeNode* root, int curr, int& sum) {
        if(!root) return;
        curr = 10 * curr + root -> val;
        if(!root -> left && !root -> right) {
            sum += curr;
        }
        dfs(root -> left, curr, sum);
        dfs(root -> right, curr, sum);
    }
    int sumNumbers(TreeNode* root) {
        int curr = 0, sum = 0;
        dfs(root, curr, sum);
        return sum;
    }
};