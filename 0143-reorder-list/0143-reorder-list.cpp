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
    void reorderList(ListNode* head) {
        
        if(head==NULL or head->next==NULL)
            return ;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *mid = slow;
        ListNode *ele = slow->next;
        while(ele->next!=NULL){
            ListNode *curr = ele->next;
            ele->next = curr->next;
            curr->next = mid->next;
            mid->next = curr;
        }
        
        ListNode *sl = head;
        ListNode *fa = mid->next;
        while(sl!=mid){
            mid->next = fa->next;
            fa->next = sl->next;
            sl->next = fa;
            sl = fa->next;
            fa = mid->next;
        }
        
    }
};