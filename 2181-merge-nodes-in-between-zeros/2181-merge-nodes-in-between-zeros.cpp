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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* head1 = new ListNode(1);
        ListNode* ans  = head1;
        while(head){
            sum += head->val;
            if(head->val == 0 && sum != 0){
                ans->next = new ListNode(sum);
                sum = 0;
                ans = ans->next;
            }
            head = head->next;
        }
        return head1->next;
    }
};