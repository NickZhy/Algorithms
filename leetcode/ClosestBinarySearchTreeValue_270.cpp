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
    int closestValue(TreeNode* root, double target) {
        if(!root) return 0;
        TreeNode* curr = root;
        int nearest = root -> val;
        while(curr) {
            if(abs(curr -> val - target) < abs(nearest - target))
                nearest = curr -> val;
            if(curr -> val < target) {
                curr = curr -> right;
            } else {
                curr = curr -> left;
            }
        }
        return nearest;
    }
};