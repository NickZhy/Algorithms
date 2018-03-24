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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!n || !head) return head;
        
        vector<ListNode*> stk;
        ListNode* curr = head;
        while(curr) {
            stk.push_back(curr);
            curr = curr -> next;
        }
        
        while(n--) stk.pop_back();
        
        if(!stk.size()) {
            curr = head -> next;
            delete head;
            return curr;
        }
        
        curr = stk.back() -> next;
        stk.back() -> next = curr -> next;
        delete curr;
        return head;
    }
};