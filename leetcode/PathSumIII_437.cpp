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
    void dfs(TreeNode* root, unordered_map<int, int>& visited, int curr, int sum, int& rst) {
        if(!root) return;
        curr += root -> val;
        rst += visited[curr - sum];
        ++visited[curr];
        dfs(root -> left, visited, curr, sum, rst);
        dfs(root -> right, visited, curr, sum, rst);
        --visited[curr];
        
    }
public:
    int pathSum(TreeNode* root, int sum) {
        int rst = 0;
        unordered_map<int, int> visited;
        visited[0] = 1;
        dfs(root, visited, 0, sum, rst);
        return rst;
    }
};