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
    bool isUnivalTree(TreeNode* root, int& count) {
        if(!root) return true;
        bool l = isUnivalTree(root -> left, count);
        bool r = isUnivalTree(root -> right, count);
        bool rst = false;
        if(l && r) {
            if(!root -> left && !root -> right) {
                rst = true;
            } else if (root -> left && root -> right) {
                rst = (root -> left -> val == root -> right -> val) && (root -> val == root -> left -> val);
            } else if (root -> left) {
                rst = (root -> val == root -> left -> val);
            } else {
                rst = (root -> val == root -> right -> val);
            }
        }
        count += rst;
        return rst;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        int count = 0;
        isUnivalTree(root, count);
        return count;
    }
};