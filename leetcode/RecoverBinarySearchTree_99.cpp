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
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* last = NULL, *mis1 = NULL, *mis2 = NULL;
        while(curr) {
            bool visit = false;
            if(!curr -> left) {
                visit = true;
            } else {
                TreeNode* tmp = curr -> left;
                while(tmp -> right && tmp -> right != curr)
                    tmp = tmp -> right;
                if(tmp -> right == curr) {
                    visit = true;
                    tmp -> right = NULL;
                } else {
                    tmp -> right = curr;
                    curr = curr -> left;
                }
            }
            if(visit) {
                if(last && last -> val > curr -> val) {
                    if(!mis1) mis1 = last;
                    mis2 = curr;
                }
                last = curr;
                curr = curr -> right;
            }
        }
        if(mis1 && mis2)
            swap(mis1 -> val, mis2 -> val);
    }
};