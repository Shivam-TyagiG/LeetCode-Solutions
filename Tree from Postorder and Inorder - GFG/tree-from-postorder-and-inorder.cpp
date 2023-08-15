//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int find_position(int in[], int element, int size){
    for(int i=0; i<size; i++){
        if(in[i] == element) return i;
    }
    return element;
}
Node* construct(int in[], int post[], int inStart, int inEnd, int posStart, int& posEnd, int size){
    if(inStart>inEnd || posStart>posEnd) return NULL;
    int element = post[posEnd];
    posEnd--;
    Node* root = new Node(element);
    int position =  find_position(in, element, size);
    root->right = construct(in, post, position+1, inEnd, posStart, posEnd, size);
    root->left = construct(in, post, inStart, position-1, posStart, posEnd, size);
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int inStart = 0;
    int inEnd = n-1;
    int posStart = 0;
    int posEnd = n-1;
    return construct(in, post, inStart, inEnd, posStart, posEnd, n);
    
    
}
