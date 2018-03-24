/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* curr = root;
        while(curr -> left) {
            TreeLinkNode* tmp = curr;
            while(true) {
                tmp -> left -> next = tmp -> right;
                if(tmp -> next) {
                    tmp -> right -> next = tmp -> next -> left;
                    tmp = tmp -> next;
                } else {
                    break;
                }
            }
            curr = curr -> left;
        }
    }
};