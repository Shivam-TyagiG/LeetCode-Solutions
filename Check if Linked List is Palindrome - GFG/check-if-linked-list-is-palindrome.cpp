//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int count = 0;
        Node* trev = head;
        while(trev != NULL)
        {
            trev = trev->next;
            count++;
        }
        if(count ==1)
        {
            return 1;
        }
        int pus = count/2;
        stack<int> s;
        
        trev = head;
        
        while(pus>0)
        {
            s.push(trev->data);
            trev = trev->next;
            pus=pus-1;
        }
        if(count%2 != 0)
        {
            trev = trev->next;
        }
        int po = count/2;
        while(!s.empty()){
            if(s.top() == trev->data)
            {
                s.pop();
                trev = trev->next;
            }
            else{
                return false;
            }
            po=po-1;
            
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends