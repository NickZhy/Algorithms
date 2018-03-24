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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* tail = head;
        while(tail -> next)  tail = tail -> next;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        while(dummy -> next != tail) {
            ListNode* tmp = dummy -> next -> next;
            dummy -> next -> next = tail -> next;
            tail -> next = dummy -> next;
            dummy -> next = tmp;
        }
        return dummy -> next;
    }
};