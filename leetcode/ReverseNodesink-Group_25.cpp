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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;
        while(curr) {
            ListNode* segStart = curr;
            ListNode* segEnd = curr;
            for(int i = 0; i < k && segEnd; ++i) segEnd = segEnd -> next;
            if(!segEnd) break;
            curr = segStart -> next;
            while(segStart -> next != segEnd) {
                ListNode* tmp = segStart -> next;
                segStart -> next =  segStart -> next -> next;
                tmp -> next = segEnd -> next;
                segEnd -> next = tmp;
            }
        }
        return dummy -> next;
    }
};