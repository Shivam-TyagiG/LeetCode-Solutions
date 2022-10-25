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
    ListNode* middleNode(ListNode* head) {
        
        int count = 0;
        ListNode* trev = head;
        while(trev != NULL)
        {
            trev = trev->next;
            count++;
            
        }
        count = count/2 +1;
        trev = head;
        while(--count)
        {
            trev=trev->next;
        }
        return trev;
        
    }
};