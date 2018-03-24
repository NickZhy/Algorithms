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
    void treeAdd(TreeNode* root, int n) {
        if(!root) return;
        root -> val += n;
        treeAdd(root -> left, n);
        treeAdd(root -> right, n);
    }
    
    TreeNode* deepCopy(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* l = deepCopy(root -> left);
        TreeNode* r = deepCopy(root -> right);
        TreeNode* rst = new TreeNode(root -> val);
        rst -> left = l;
        rst -> right = r;
        return rst;
    }
    
    vector<TreeNode*> helper(int n) {
        if(n == 0) return vector<TreeNode*>(1, NULL);
        vector<TreeNode*> rst;
        for(int i = 0; i < n; ++i) {
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n - 1 - i);
            for(TreeNode* r: right) treeAdd(r, i + 1);
            for(TreeNode* l: left)
                for(TreeNode* r: right) {
                    TreeNode* root = new TreeNode(i + 1);
                    root -> left = deepCopy(l);
                    root -> right = deepCopy(r);
                    rst.push_back(root);
                }
        }
        return rst;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return helper(n);
    }
};