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
    ListNode* revLinkedList(ListNode* head) {
        ListNode* last = NULL;
        while(head -> next) {
            ListNode* tmp = head -> next;
            head -> next = last;
            last = head;
            head = tmp;
        }
        head -> next = last;
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *tmp1, *tmp2, *tail;
        tmp1 = tmp2 = head;
        while(tmp1 && tmp1 -> next) {
            tmp1 = tmp1 -> next -> next;
            tmp2 = tmp2 -> next;
        }
        
        tmp1 = head;
        tmp2 = tail = revLinkedList(tmp2);
        
        bool result = true;
        while(tmp1 && tmp2 && result) {
            if(tmp1 -> val != tmp2 -> val) result = false;
            tmp1 = tmp1 -> next;
            tmp2 = tmp2 -> next;
        }
        revLinkedList(tail);
        return result;
    }
};