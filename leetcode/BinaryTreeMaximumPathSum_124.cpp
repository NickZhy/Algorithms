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
    int maxSum = INT_MIN;
    int maxSinglePathSum(TreeNode* root) {
        if(!root) return 0;
        int l = maxSinglePathSum(root -> left);
        int r = maxSinglePathSum(root -> right);
        maxSum = max(maxSum, max(l,  0) + max(r, 0) + root -> val);
        return max(max(l, r) + root -> val, root -> val);
    }
    
    int maxPathSum(TreeNode* root) {
        maxSinglePathSum(root);
        return maxSum;
    }
};