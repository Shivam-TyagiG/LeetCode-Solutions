class Solution {
public:
    void insertattail(Node* &head, Node*& tail, int data){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail=newnode;
        }
    }
public:
    Node* copyRandomList(Node* head) {

        //first step
        //craete a clone node
        if(head==NULL) return NULL;
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }

        //second step
        //add clone between orignal and clone node
        temp = head;
        Node* clonenode = clonehead;
        while(clonenode && temp){
            Node* next = temp->next;
            temp->next = clonenode;

            Node* clonenext = clonenode->next;
            clonenode->next = next;

            clonenode = clonenext;
            temp = next;
        }

        //stemp 3
        //copy the random variable
        temp=head;
        while(temp!=NULL){
            if(temp->next){
                temp->next->random=temp->random?temp->random->next:temp->random;
            }
            if(temp->next!=NULL){
                temp = temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }

        //step4
        temp = head;
        clonenode = clonehead;
        while(temp && clonenode){
            temp->next = clonenode->next;
            temp = temp->next;

            if(temp!=NULL){
                clonenode->next = temp->next;
            }
            clonenode=clonenode->next;
        }
        return clonehead;
        
    }
};