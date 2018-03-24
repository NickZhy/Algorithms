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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int rst = 0;
        TreeNode *t = root -> left;
        int cl = 0, cr = 0;
        while(t) {
            t = t -> left;
            ++cl;
        }
        while(root) {
            t = root -> right;
            cr = 0;
            while(t) {
                t = t -> left;
                ++cr;
            }
            if(cl == cr) {
                rst += (1 << cl);
                root = root -> right;
                cl = cr - 1;
            } else {
                rst += (1 << cr);
                root = root -> left;
                cl = cl - 1;
            }
        }
        return rst;
    }
};