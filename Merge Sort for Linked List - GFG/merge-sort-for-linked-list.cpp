//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* find_mid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* temp1, Node* temp2){
        if(temp1==NULL) return temp2;
        if(temp2==NULL) return temp1;
        Node* head = new Node(-1);
        Node* temp = head;
        while(temp1 && temp2){
            if(temp1->data < temp2->data){
                temp->next = temp1;
                temp1=temp1->next;
                temp=temp->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
        }
        while(temp1){
            temp->next = temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
        while(temp2){
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
        if(head==NULL) return head;
        return head->next;
    }
    
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        Node* mid = find_mid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        Node* result = merge(left, right);
        return result;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends