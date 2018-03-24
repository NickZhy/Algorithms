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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p -> right) {
            TreeNode* curr = p;
            curr = curr -> right;
            while(curr -> left) curr = curr -> left;
            return curr;
        }
        vector<TreeNode*> path;
        TreeNode* curr = root;
        while(curr != p) {
            path.push_back(curr);
            if(p -> val < curr -> val) curr = curr -> left;
            else curr = curr -> right;
        }
        while(path.size()) {
            curr = path.back();
            path.pop_back();
            if(curr -> val >= p -> val) return curr;
        }
        return NULL;
    }
};