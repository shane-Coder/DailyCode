/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        int l=1;
        ListNode *curr = head, *prev = head;
        while(prev->next != NULL){
            prev = prev->next;
            l++;
        }
        prev->next = head;
        k = k%l;
        if(k){
            for(int i=0; i<l-k; i++)
                prev = prev->next;
        }
        curr = prev->next;
        prev->next = NULL;
        return curr;
    }
};