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
    bool dfs(TreeNode* root, int& maxVal, int& minVal) {
        if(!root) return true;
        maxVal = minVal = root -> val;
        if(root -> left) {
            int maxL = INT_MIN, minL = INT_MAX;
            if(!dfs(root -> left, maxL, minL))
                return false;
            if(maxL >= root -> val) 
                return false;
            minVal = minL;
        } 
        
        if(root -> right) {
            int maxR = INT_MIN, minR = INT_MAX;
            if(!dfs(root -> right, maxR, minR))
                return false;
            if(minR <= root -> val) 
                return false;
            maxVal = maxR;
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        int a, b;
        return dfs(root, a, b);
    }
};