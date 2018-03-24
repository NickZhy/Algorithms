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
    int minExpt(TreeNode* root, int expt) {
        if(!root) return -1;
        if(root -> val != expt) return root -> val;
        int l = minExpt(root -> left, expt);
        int r = minExpt(root -> right, expt);
        if(l == -1 || r == -1) return max(l, r);
        return min(l, r);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        return minExpt(root, root -> val);
    }
};