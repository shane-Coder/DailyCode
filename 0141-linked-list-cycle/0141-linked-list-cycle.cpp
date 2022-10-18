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
        if(head==NULL)
            return false;
        ListNode *prev = head;
        ListNode *curr = head;
        while(curr!=NULL and curr->next!=NULL){
            curr = curr->next->next;
            prev = prev->next;
            if(curr==prev)
                return true;
        }
        return false;
    }
};