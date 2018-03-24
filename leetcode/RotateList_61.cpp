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
    ListNode* rotateRight(ListNode* head, int k) {
         ListNode *rst;
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *tmp1=head;
        int count=1;
        while(tmp1->next!=NULL){
            tmp1=tmp1->next;
            ++count;
        }
        tmp1->next=head;
        int step=count-k%count;
        tmp1=head;
        for(int i=1;i<step;++i){
            tmp1=tmp1->next;
        }
        rst=tmp1->next;
        tmp1->next=NULL;
        return rst;
    }
};