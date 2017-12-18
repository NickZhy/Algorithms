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
    long maxVal = INT_MIN;
public:
    long maxLinkSum(TreeNode* root) {
        long l = INT_MIN, r = INT_MIN;
        long val = root -> val;
        if(root -> left)
            l = maxLinkSum(root -> left);
        if(root -> right) 
            r = maxLinkSum(root -> right);
        long mPathSum = max(max(val + l + r, val), max(val + l, val + r));
        maxVal = max(maxVal, mPathSum);
        return max(val, max(l + val, r + val));
    }
    int maxPathSum(TreeNode* root) {
        maxLinkSum(root);
        return maxVal;
    }
};
