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
    TreeNode* subBuildTree(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2) {
        if(e1 < s1) return NULL;
        int val = postorder[e2];
        TreeNode* curr = new TreeNode(val);
        int c = 0;
        while(s1 + c <= e1 && inorder[s1 + c] != val) ++c;
        curr -> left = subBuildTree(inorder, s1, s1 + c - 1, postorder, s2, s2 + c - 1);
        curr -> right = subBuildTree(inorder, s1 + c + 1, e1, postorder, s2 + c, e2 - 1);
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        return subBuildTree(inorder, 0, len - 1, postorder, 0, len - 1);
    }
};