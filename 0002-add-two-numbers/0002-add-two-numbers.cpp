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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 || l2 || carry){
            int data=0;
            if(l1)  data+=l1->val;
            if(l2)  data+=l2->val;
            data=data+carry;
            carry = data/10;
            data = data%10;
            if(head){
                ListNode* add = new ListNode(data);
                tail->next = add;
                tail=tail->next;
            }
            else{
                ListNode* add = new ListNode(data);
                head = add;
                tail = add;
            }
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return head;
    }
};