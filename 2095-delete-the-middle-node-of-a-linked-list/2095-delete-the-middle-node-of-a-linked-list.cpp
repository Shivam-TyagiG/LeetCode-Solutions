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

int solve(ListNode* head)
{
    int count = 1;
    while(head->next != NULL)
    {
        count++;
        head = head->next;
    }
    
    if(count%2 == 0)
    {
        count = count/2;
    }
    else{
        count = count/2 ;
    }
    
    return count-1 ;
}

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL || head -> next ==NULL)
        {
            return NULL;
        }
        
        int mid = solve(head);
        
        ListNode* next = head;
        while(mid-- && next->next != NULL)
        {
            next = next->next;
        }
        ListNode* temp = next->next;
        if(next->next != NULL)
        {
            next->next = next->next->next;
            
        }
        else
        {
            next->next = next->next;
        }
        
        delete temp;
        return head;
    }
};