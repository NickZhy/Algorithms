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
    void reorderList(ListNode* head) {
        if(!head || !head -> next) return;
        ListNode *mid = head, *curr = head -> next;
        while(curr && curr -> next) {
            mid = mid -> next;
            curr = curr -> next -> next;
        }
        
        // reverse the tail
        curr = mid -> next -> next;
        mid -> next -> next = NULL;
        ListNode* tail;
        while(curr) {
            tail = curr -> next;
            curr -> next = mid -> next;
            mid -> next = curr;
            curr = tail;
        }
        
        // reorder the tail
        tail = mid -> next;
        mid -> next = NULL;
        curr = head;
        mid = tail;
        while(curr && tail) {
            tail = tail -> next;
            mid -> next = curr -> next;
            curr -> next = mid;
            mid = tail;
            curr = curr -> next -> next;
        }
    }
};