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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        ListNode* trev = head->next;
        ListNode* prev = head;
        head->next = NULL;
        while(trev  != NULL)
        {
            head = trev;
            trev = trev->next;
            head->next = prev;
            prev = head;
        }
        
        return head;
        
    }
};