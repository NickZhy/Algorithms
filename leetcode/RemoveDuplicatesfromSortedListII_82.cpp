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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;
        while(curr && curr -> next && curr -> next -> next) {
            if(curr -> next -> val == curr -> next -> next -> val) {
                int dupEle = curr -> next -> val;
                ListNode* tmp = curr -> next;
                while(tmp && tmp -> val == dupEle) {
                    curr -> next = tmp -> next;
                    delete tmp;
                    tmp = curr -> next;
                }
            } else {
                curr = curr -> next;
            }
        }
        curr = dummy -> next;
        delete dummy;
        return curr;
    }
};