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
    vector<TreeNode*> makeIterator(vector<TreeNode*>& stk, bool reverse) {
        vector<TreeNode*> rst;
        for(TreeNode* node: stk) {
            if(!reverse) {
                if(rst.size() && rst.back() -> right == node) 
                    rst.pop_back();
            } else {
                if(rst.size() && rst.back() -> left == node) 
                    rst.pop_back();
            }
            rst.push_back(node);
        }
        return rst;
    }
    
    void next(vector<TreeNode*>& it, bool reverse) {
        if(!it.size()) return;
        TreeNode* rst = it.back(); it.pop_back();
        if(!reverse) {
            if(rst -> right) {
                TreeNode* tmp = rst -> right;
                while(tmp) {
                    it.push_back(tmp);
                    tmp = tmp -> left;
                }
                
            }
        } else {
            if(rst -> left) {
                TreeNode* tmp = rst -> left;
                while(tmp) {
                    it.push_back(tmp);
                    tmp = tmp -> right;
                }
            }
        }
    }
    
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if(!root) return {};
        TreeNode* curr = root, *minDistNode = root;
        double minDist = abs(target - root -> val);
        vector<TreeNode*> stk;
        while(curr) {
            double dist = abs(target - curr -> val);
            if(dist < minDist) {
                minDistNode = curr;
                minDist = dist;
            }
            stk.push_back(curr);
            if(target < curr -> val) {
                curr = curr -> left;
            } else {
                curr = curr -> right;
            }
        }
        
        while(stk.back() != minDistNode) stk.pop_back();
        
        vector<TreeNode*> it = makeIterator(stk, false);
        vector<TreeNode*> revIt = makeIterator(stk, true);
        next(it, false); // now two iterators are pointing to minDistNode, so move one of them.
        
        vector<int> rst;
        for(int i = 0; i < k; ++i) {
            double a = numeric_limits<double>::max();
            double b = a;
            if(it.size()) 
                a = abs(it.back() -> val - target);
            
            if(revIt.size()) 
                b = abs(revIt.back() -> val - target);
            if(a < b) {
                rst.push_back(it.back() -> val);
                next(it, false);
            } else {
                rst.push_back(revIt.back() -> val);
                next(revIt, true);
            }
        }
        return rst;
    }
};