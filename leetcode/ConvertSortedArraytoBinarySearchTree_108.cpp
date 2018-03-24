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
    TreeNode* helper(vector<int>& nums, int i, int j) {
        if(i > j) return NULL;
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = helper(nums, i, mid - 1);
        root -> right = helper(nums, mid + 1, j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};