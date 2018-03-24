/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* curr = head;
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* tmp = dummy;
        while(curr) {
            tmp -> next = new RandomListNode(curr -> label);
            tmp = tmp -> next;
            mp[curr] = tmp;
            curr = curr -> next;
        }
        curr = head;
        tmp = dummy -> next;
        while(tmp) {
            if(curr -> random)
                tmp -> random = mp[curr -> random];
            tmp = tmp -> next;
            curr = curr -> next;
        }
        tmp = dummy -> next;
        delete dummy;
        return tmp;
    }
};