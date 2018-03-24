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

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        unordered_map<int, vector<int>> rst;
        int minVer = 0, maxVer = 0;
        
        queue<pr> q;
        q.push(pr(root, 0));
        while(q.size()) {
            pr curr = q.front();
            q.pop();
            minVer = min(minVer, curr.second);
            maxVer = max(maxVer, curr.second);
            rst[curr.second].push_back(curr.first -> val);
            if(curr.first -> left)
                q.push(pr(curr.first -> left, curr.second - 1));
            if(curr.first -> right)
                q.push(pr(curr.first -> right, curr.second + 1));
        }
        
        vector<vector<int>> result;
        for(int i = minVer; i <= maxVer; ++i)
            result.push_back(rst[i]);
        return result;
    }
};