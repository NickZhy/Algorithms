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
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode *t1 = head, *t2 = head -> next;
        while(t2 && t2 -> next) {
            t1 = t1 -> next;
            t2 = t2 -> next -> next;
        }
        t2 = t1 -> next;
        t1 -> next = NULL;
        t1 = sortList(head);
        t2 = sortList(t2);

        ListNode *rst = new ListNode(0);
        ListNode *tail = rst;
        while(t1 && t2) {
            if(t1 -> val < t2 -> val) {
                tail -> next = t1;
                t1 = t1 -> next;
            } else {
                tail -> next = t2;
                t2 = t2 -> next;
            }
            tail = tail -> next;
        }
        if(t1) tail -> next = t1;
        if(t2) tail -> next = t2;
        tail = rst -> next;
        delete rst;
        return tail;
        
    }
};