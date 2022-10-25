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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL)
        {
            return list2;
        }
        if(list2 == NULL)
        {
            return list1;
        }
        
        ListNode* head;
        ListNode* trav1 = list1;
        ListNode* trav2 = list2;
        if(trav1->val <=  trav2->val)
        {
            head = trav1;
            trav1=trav1->next;
            
        }
        else{
            head = trav2;
            trav2 = trav2->next;
        }
        ListNode* ans = head;
        while(trav1 != NULL && trav2 != NULL){
            
            
            if(trav1->val <=  trav2->val)
            {
                //cout<<trav1->val<<" ";
                head->next = trav1;
                head = head->next;
                trav1 = trav1->next;
                
            }
            
            else{
                
                //cout<<head->val<< " ";
                
                head->next = trav2;
                head = head->next;
                trav2 = trav2->next;
            }
            
            
        }
        if(trav1 != NULL)
        {
            head->next = trav1;
        }
        if(trav2 != NULL)
        {
            head->next = trav2 ;
        }
        
        return ans;
        
    }
};