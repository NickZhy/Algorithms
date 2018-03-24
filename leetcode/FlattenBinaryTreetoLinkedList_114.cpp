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
    TreeNode* helper(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* lTail = helper(root -> left);
        TreeNode* rTail = helper(root -> right);
        
        if(lTail && rTail) {
            lTail -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
            return rTail;
        } else if(lTail) {
            root -> right = root -> left;
            root -> left = NULL;
            return lTail;
        } else if(rTail) {
            return rTail;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};