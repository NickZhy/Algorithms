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
    static bool cmp(ListNode* a, ListNode* b) {
        if(!a) return true;
        if(!b) return false;
        return a -> val > b -> val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        make_heap(lists.begin(), lists.end(), cmp);
        while(lists.size()) {
            pop_heap(lists.begin(), lists.end(), cmp);
            curr -> next = lists.back();
            lists.pop_back();
            if(!curr -> next) continue;
            curr = curr -> next;
            if(curr -> next) {
                lists.push_back(curr -> next);
                curr -> next = NULL;
                push_heap(lists.begin(), lists.end(), cmp);
            }
        }
        curr = dummy -> next;
        delete dummy;
        return curr;
    }
};