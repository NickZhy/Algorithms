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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;
        for(int i = 1; i < m; ++i) 
            curr = curr -> next;
        int num = n - m + 1;
        ListNode* remains = curr -> next;
        ListNode* tail = remains;
        for(int i = 0; i < num; ++i) {
            ListNode* tmp = remains -> next;
            remains -> next = curr -> next;
            curr -> next = remains;
            remains = tmp;
        }
        tail -> next = remains;
        curr = dummy -> next;
        delete dummy;
        return curr;
    }
};