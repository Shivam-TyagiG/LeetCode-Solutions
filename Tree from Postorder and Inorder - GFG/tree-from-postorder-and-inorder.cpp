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
void createmap(int in[],map<int,int> &mapping,int n)
{
    for(int i=0;i<n;i++)
    {
        mapping[in[i]] = i;
    }
}
Node* solve(int in[],int post[],int inorderstart,int inorderend,int postorderstart,int &postorderend, map<int,int> &mapping)
{
    if(postorderend < 0 || inorderstart > inorderend)
    {
        return NULL;
    }
    
    int element = post[postorderend--];
    Node* root = new Node(element);
    int position = mapping[element];
    
    //recursive call
    root->right = solve(in, post, position+1,inorderend,postorderstart,postorderend,mapping);
    root->left = solve(in, post, inorderstart,position-1,postorderstart,postorderend,mapping);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    map<int,int> mapping;
    createmap(in,mapping,n);
    int postorderend = n-1;
    Node* ans = solve(in , post, 0, n-1, 0, postorderend, mapping);
    return ans;
}
