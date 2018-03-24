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
    double average(vector<int>& vec) {
        double r = 0;
        for(int ele: vec) 
            r += ele;
        return r/vec.size();
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return vector<double>();
        vector<vector<int>> lSort;
        queue<TreeNode*> qNode;
        queue<int> qLevel;
        qNode.push(root);
        qLevel.push(0);
        while(qNode.size()) {
            TreeNode* curr = qNode.front(); qNode.pop();
            int l = qLevel.front(); qLevel.pop();
            if(l >= lSort.size())
                lSort.push_back(vector<int>());
            lSort[l].push_back(curr -> val);
            if(curr -> left) {
                qNode.push(curr -> left);
                qLevel.push(l + 1);
            }
            if(curr -> right) {
                qNode.push(curr -> right);
                qLevel.push(l + 1);
            }
        }
        vector<double> rst;
        for(vector<int>& l: lSort)
            rst.push_back(average(l));
        return rst;
    }
};