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
    ListNode* reverseList(ListNode* l) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = l;
        while(curr) {
            ListNode* tmp = curr;
            curr = curr -> next;
            tmp -> next = dummy -> next;
            dummy -> next = tmp;
        }
        curr = dummy -> next;
        delete dummy;
        return curr;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr1 = l1, *curr2 = l2, *t = NULL;
        int remain = 0;
        while(curr1 || curr2) {
            int a = curr1? curr1 -> val: 0;
            int b = curr2? curr2 -> val: 0;
            int tmp = remain + a + b;
            t = dummy -> next;
            dummy -> next = new ListNode(tmp % 10);
            dummy -> next -> next = t;
            remain = tmp / 10;
            if(curr1) curr1 = curr1 -> next;
            if(curr2) curr2 = curr2 -> next;
        }
        if(remain) {
            t = dummy -> next;
            dummy -> next = new ListNode(remain);
            dummy -> next -> next = t;
        }
        reverseList(l1);
        reverseList(l2);
        t = dummy -> next;
        delete dummy;
        return t;
    }
};