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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;
        while(curr && curr -> next) {
            if(curr -> next -> val == val) {
                ListNode* tmp = curr -> next;
                curr -> next = curr -> next -> next;
                delete tmp;
            } else {
                curr = curr -> next;
            }
        }
        curr = dummy -> next;
        delete dummy;
        return curr;
    }
};