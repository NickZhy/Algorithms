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
    int maxLen;
    int helper(TreeNode* root) {
        if(!root) return 0;
        int rst = 1;
        int maxPath = 1;
        int l = helper(root -> left);
        int r = helper(root -> right);
        if(l > 0 && root -> left -> val == root -> val) {
            rst = max(rst, l + 1);
            maxPath += l;
        }
        if(r > 0 && root -> right -> val == root -> val) {
            rst = max(rst, r + 1);
            maxPath += r;
        }
        maxLen = max(maxLen, maxPath);
        return rst;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        maxLen = 0;
        helper(root);
        return maxLen - 1;
    }
};