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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head->next == NULL && n==1)
        {
            return NULL;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        if(count == n)
        {
            return head->next;
        }
        count = count - n -1;
        temp = head;
        ListNode* next = NULL;
        
        
        
        while(count>0)
        {
            temp = temp->next;
            count--;
        }
        next = temp->next->next;
        ListNode* del = temp->next;
        delete del;
        temp->next = next;
        
        return head;
        
    }
};