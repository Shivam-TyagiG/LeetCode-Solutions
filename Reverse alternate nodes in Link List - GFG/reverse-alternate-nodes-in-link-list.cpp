//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    struct Node* reverse(struct Node*& rev){
        struct Node* head = rev;
        struct Node* prev = NULL;
        while(head){
            struct Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd==NULL  || odd->next==NULL) return ;
        struct Node* temp1 = odd;
        struct Node* temp2 = odd->next;
        struct Node* head = temp2;
        struct Node* temp = odd->next->next;
        bool first = true;
        while(temp){
            if(first){
                temp1->next = temp;
                temp1 = temp1->next;
            }
            else{
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
            first = !first;
        }
        temp1->next = NULL;
        temp2->next = NULL;
        // while(head!=NULL){
        //     cout<<head->data<<" ";
        //     head = head->next;
        // }
        // cout<<endl;
        temp1->next = reverse(head);
        return ;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends