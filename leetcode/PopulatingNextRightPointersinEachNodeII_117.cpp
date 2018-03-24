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
        TreeLinkNode* layer = root;
        while(layer) {
            TreeLinkNode* t = layer;
            TreeLinkNode* nextLeft = NULL, *curr = NULL;
            while(t) {
                if(t -> left) {
                    if(!nextLeft) {
                        nextLeft = t -> left;
                        curr = nextLeft;
                    } else {
                        curr -> next = t -> left;
                        curr = curr -> next;
                    }
                }
                if(t -> right) {
                    if(!nextLeft) {
                        nextLeft = t -> right;
                        curr = nextLeft;
                    } else {
                        curr -> next = t -> right;
                        curr = curr -> next;
                    }
                }
                t = t -> next;
            }
            layer = nextLeft;
        }   
    }
};