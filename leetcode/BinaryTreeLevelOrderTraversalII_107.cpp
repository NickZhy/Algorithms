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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int>> l = levelOrderBottom(root -> left);
        vector<vector<int>> r = levelOrderBottom(root -> right);
        if(l.size() < r.size()) {
            vector<vector<int>> tmp(r.size() - l.size());
            l.insert(l.begin(), tmp.begin(), tmp.end());
        }
        for(int i = 0; i < r.size(); ++i) {
            int idx = l.size() - r.size() + i;
            l[idx].insert(l[idx].end(), r[i].begin(), r[i].end());
        }
        l.push_back(vector<int>(1, root -> val));
        return l;
    }
};