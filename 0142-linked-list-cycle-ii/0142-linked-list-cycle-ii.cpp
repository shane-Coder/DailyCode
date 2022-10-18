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
    ListNode *detectCycle(ListNode *head) {
        ListNode *prev = head;
        ListNode *curr = head;
        while(curr!=NULL and curr->next!=NULL){
            curr = curr->next->next;
            prev = prev->next;
            if(curr==prev){
                curr = curr;
                prev = head;
                while(prev!=curr){
                    prev = prev->next;
                    curr = curr->next;
                }
                return prev;
            }
        }
        return NULL;
    }
};