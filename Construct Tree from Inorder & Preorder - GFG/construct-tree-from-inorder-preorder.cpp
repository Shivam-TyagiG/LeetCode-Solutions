//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
    int findposition(int in[],int element, int size)
    {
        for(int i=0;i<size;i++)
        {
            if(in[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    
    private:
    Node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int size)
    {
        if(index>=size || inorderstart > inorderend)
        {
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = findposition(in,element,size);
        
        //recursive calls
        root->left = solve(in ,pre, index, inorderstart, position-1,size);
        root->right = solve(in ,pre, index, position+1, inorderend, size);
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        return solve(in,pre,preorderindex,0,n-1,n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends