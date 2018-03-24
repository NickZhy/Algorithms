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
    void findMode(TreeNode* root, int& last, int& count, int& max, vector<int>& rst) {
        if(!root) return;
        findMode(root -> left, last, count, max, rst);
        if(count < 0 || root -> val != last) {
            if(count >= max) {
                if(count > max) rst.clear();
                max = count;
                rst.push_back(last);
            }
            count = 1;
        } else {
            ++count;
        }
        last = root -> val;
        findMode(root -> right, last, count, max, rst);
    }
public:
    vector<int> findMode(TreeNode* root) {
        int last = INT_MAX, count = -1, max = 0;
        vector<int> rst;
        findMode(root, last, count, max, rst);
        if(count >= max) {
            if(count > max) rst.clear();
            rst.push_back(last);
        }
        return rst;
    }
};