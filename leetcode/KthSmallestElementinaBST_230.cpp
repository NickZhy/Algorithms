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
    int dfs(TreeNode* root, int& rank, int k) {
        if(root == NULL) return 0;
        int l = dfs(root -> left, rank, k);
        if(++rank > k) return l;
        if(rank == k) return root -> val;
        return dfs(root -> right, rank, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int rank = 0;
        return dfs(root, rank, k);
    }
};