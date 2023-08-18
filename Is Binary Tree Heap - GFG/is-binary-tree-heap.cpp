//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  private:
    int countnode(struct Node* node){
        if(node == NULL) return 0;
        return 1+ countnode(node->left)+ countnode(node->right);
    }
    
    bool iscbt(struct Node* root, int totalnode, int i){
        if(root==NULL) return 1;
        if(i>=totalnode) return 0;
        else{
            bool left = iscbt(root->left, totalnode, 2*i+1);
            bool right = iscbt(root->right, totalnode, 2*i+2);
            return left && right;
        }
    }
    
    bool checkheap(struct Node* root){
        if(root==NULL || root->left==NULL && root->right==NULL) return 1;
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = checkheap(root->left);
            bool right = checkheap(root->right);
            return (left && right  && ((root->data > root->left->data) && (root->data > root->right->data)));
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int totalnode = countnode(tree);
        bool cbt = iscbt(tree, totalnode, 0);
        if(!cbt) return 0;
        bool ans =  checkheap(tree);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends