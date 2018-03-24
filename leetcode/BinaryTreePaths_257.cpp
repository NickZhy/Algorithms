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
    void addNode(int val,vector<string>& vec){
        for(int i=0;i<vec.size();++i){
            vec[i]=to_string(val)+"->"+vec[i];
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> output;
        if(root==NULL){
            return output;
        }
        if(!root->left&&!root->right){
            output.push_back(to_string(root->val));
            return output;
        }
        output=binaryTreePaths(root->left);
        vector<string> r=binaryTreePaths(root->right);
        addNode(root->val,output);
        addNode(root->val,r);
        output.insert(output.end(),r.begin(),r.end());
        return output;
    }
};