class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(c<n){
            p2=p2->next;
            c++;
        }

        if(p2==NULL){
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        while(p2->next){
            p1=p1->next;
            p2=p2->next;
        }
            ListNode* temp = p1->next;
            p1->next = p1->next->next;
            delete(temp);
            return head;       
        
    }
};