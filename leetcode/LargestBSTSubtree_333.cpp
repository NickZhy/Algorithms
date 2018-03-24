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
    int maxSize = 0;
    int dfs(TreeNode* root, int& minNode, int& maxNode) {
        if(!root) {
            maxNode = INT_MIN;
            minNode = INT_MAX;
            return 0;
        }
        int lMin, lMax, rMin, rMax;
        int lNode = dfs(root -> left, lMin, lMax);
        int rNode = dfs(root -> right, rMin, rMax);
        if(lNode >= 0 && rNode >= 0) {
            if(lMax < root -> val && rMin > root ->val) {
                int result = lNode + rNode + 1;
                maxSize = max(maxSize, result);
                maxNode = root -> right? rMax: root -> val;
                minNode = root -> left? lMin: root ->val;
                return result;
            }
        }
        return -1;
    }
    int largestBSTSubtree(TreeNode* root) {
        int minNode, maxNode;
        dfs(root, minNode, maxNode);
        return maxSize;
    }
};