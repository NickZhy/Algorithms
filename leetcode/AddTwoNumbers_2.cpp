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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        int tmp=l1->val+l2->val;
        ListNode *head=new ListNode(tmp%10);
        ListNode *tail=head;
        tmp=tmp/10;
        l1=l1->next;
        l2=l2->next;
        while(l1||l2){
            tmp=(l1?l1->val:0)+(l2?l2->val:0)+tmp;
            tail->next=new ListNode(tmp%10);
            tmp=tmp/10;
            tail=tail->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        };
        if(tmp!=0){
            tail->next=new ListNode(tmp);
        }
        return head;
    }
};