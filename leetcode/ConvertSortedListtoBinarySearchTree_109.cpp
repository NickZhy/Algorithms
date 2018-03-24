/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head -> next) return new TreeNode(head -> val);
        
        ListNode* curr = head -> next -> next, *mid = head;
        while(curr && curr -> next) {
            curr = curr -> next -> next;
            mid = mid -> next;
        }
        curr = mid -> next;
        mid -> next = NULL;
        TreeNode* root = new TreeNode(curr -> val);
        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(curr -> next);
        mid -> next = curr;
        return root;
    }
};