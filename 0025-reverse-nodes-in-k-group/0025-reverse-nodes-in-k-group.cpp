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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int count = 0;
        while(curr!=NULL && count<k){
            count++;
            curr = curr->next;
        }
        if(count<k) return head;
        count=0;
        curr = head;
        while(curr!=NULL && count<k){
            forward = curr->next; 
            curr->next = prev ; 
            prev = curr;
            curr = forward;
            count++;
        }
        if(curr) head->next = reverseKGroup(curr, k);
        return prev;
    }
    
};