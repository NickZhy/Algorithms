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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(!root) return rst;
        
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 0));
        while(q.size()) {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int level = curr.second;
            if(rst.size() == level) rst.push_back(vector<int>());
            rst[level].push_back(node -> val);
            
            if(node -> left)
                q.push(pair<TreeNode*, int>(node -> left, level + 1));
            
            if(node -> right)
                q.push(pair<TreeNode*, int>(node -> right, level + 1));
        }
        
        bool sign = true;
        for(vector<int>& l: rst) {
            if(!sign) reverse(l.begin(), l.end());
            sign = !sign;
        }
        return rst;
    }
};