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
    bool hasCycle(ListNode *head) {
        ListNode* first = head, *second = head;
        while(first && second && second -> next) {
            first = first -> next;
            second = second -> next -> next;
            if(first == second) return true;
        }
        return false;
    }
};