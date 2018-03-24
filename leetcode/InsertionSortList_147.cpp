/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *rst = new ListNode(0);
        ListNode *curr = NULL;
        while(dummy -> next) {
            curr = dummy;
            ListNode* maxNode = dummy;
            while(curr -> next) {
                if(curr -> next -> val > maxNode -> next -> val) 
                    maxNode = curr;
                curr = curr -> next;
            }
            curr = maxNode -> next;
            maxNode -> next = curr -> next;
            curr -> next = rst -> next;
            rst -> next = curr;
        }
        curr = rst -> next;
        delete dummy;
        delete rst;
        return curr;
    }
};