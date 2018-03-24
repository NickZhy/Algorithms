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
    TreeNode* rst;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;
        bool l = helper(root -> left, p, q);
        bool r = helper(root -> right, p, q);
        if(root == p || root == q) {
            if(l || r) {
                rst = root;
                return false;
            }
            return true;
        }
        
        if(l && r) {
            rst = root;
            return false;
        }
        return l || r;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rst = NULL;
        helper(root, p, q);
        return rst;
    }
};