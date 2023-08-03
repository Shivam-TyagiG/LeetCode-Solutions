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
     ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL) return head;
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* after = NULL;
        while(current != NULL)
        {
            after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }
        return prev;
    }
    void insert(ListNode* &ansH , ListNode* &ansT, int data)
    {
        if(ansH == NULL)
        {
            ListNode* temp = new ListNode(data);
            ansH = temp;
            ansT = temp;
        }
        else
        {
            ListNode* temp = new ListNode(data);
            ansT->next = temp;
            ansT = temp;
        }
        
    }
    ListNode* add(ListNode* head1 , ListNode* head2)
    {
        int carry = 0;
        ListNode* ansH = NULL ;
        ListNode* ansT = NULL;
        while(head1 != NULL || head2 != NULL || carry != 0)
        {
            int data = 0;
            if(head1 != NULL)data += head1->val;
            if(head2 != NULL) data += head2->val;
            data += carry;
            insert(ansH , ansT , data%10);
            carry = data/10;

            if(head1 != NULL) head1 = head1->next;
            if(head2 != NULL) head2 = head2->next;

        }
        return ansH;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // l1 = reverse(l1);
        // l2 = reverse(l2);
        ListNode* ans = add(l1 , l2);

        return ans;
    }
};