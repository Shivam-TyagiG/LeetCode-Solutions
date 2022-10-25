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
        /*
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* intersection;
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast->next != NULL)
            {
                fast=fast->next;
            }
            slow=slow->next;
            
            if(slow == fast )
            {
                intersection = slow;
                break;
            }
        }
        
        
        if(slow == NULL || fast==NULL)
        {
            return NULL;
        }
        cout<<"yes"<<endl;
        
        while(head != intersection)
        {
            head = head->next;
            intersection = intersection->next;
            
        }
        cout<<"N0"<<endl;
        return head;
        */
        if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL; 
    }
};