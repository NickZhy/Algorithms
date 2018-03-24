/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*, int> pr;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> rst;
        if(!root) return rst;
        queue<pr> q;
        q.push(pr(root, 0));
        while(q.size() > 0) {
            pr curr = q.front();
            TreeNode* currNode = curr.first;
            int level = curr.second;
            q.pop();
            if(level == rst.size())
                rst.push_back(vector<int>());
            rst[level].push_back(currNode -> val);
            if(currNode -> left) 
                q.push(pr(currNode -> left, level + 1));
            
            if(currNode -> right)
                q.push(pr(currNode -> right, level + 1));
        }
        return rst;
    }
};