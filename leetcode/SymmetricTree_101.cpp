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
    bool SymTree(TreeNode* a, TreeNode* b) {
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a -> val != b -> val) return false;
        return SymTree(a -> left, b -> right) && SymTree(a -> right, b -> left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return SymTree(root -> left, root -> right);
    }
};