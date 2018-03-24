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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ls = new ListNode(0);
        ListNode *gt = new ListNode(0);
        ListNode *curr1 = ls, *curr2 = gt;
        while(head) {
            if(head -> val < x) {
                curr1 -> next = head;
                curr1 = curr1 -> next;
            } else {
                curr2 -> next = head;
                curr2 = curr2 -> next;
            }
            head = head -> next;
        }
        curr1 -> next = gt -> next;
        curr2 -> next = NULL;
        curr1 = ls -> next;
        delete ls;
        delete gt;
        return curr1;
    }
};