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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *t1 = headA, *t2 = headB;
        while(t1) {
            t1 = t1 -> next;
            ++lenA;
        }
        while(t2) {
            t2 = t2 -> next;
            ++lenB;
        }
        t1 = headA, t2 = headB;
        
        while(lenA > lenB) {
            --lenA;
            t1 = t1 -> next;
        }
        while(lenB > lenA) {
            --lenB;
            t2 = t2 -> next;
        }
        while(t1 != t2) {
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return t1;
    }
};