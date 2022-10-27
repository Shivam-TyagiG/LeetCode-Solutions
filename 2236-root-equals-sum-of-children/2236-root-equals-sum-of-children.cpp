/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void summing(TreeNode* root,int &sum)
    {
        if(root == NULL)
        {
            return ;
        }
        
        summing(root->left,sum);
        sum = sum + root->val;
        summing(root->right,sum);
    }
    bool checkTree(TreeNode* root) {
        
        int sum = 0;
        summing(root,sum);
        cout<<sum;
        if(sum-root->val == root->val)
        {
            return 1;
        }
        else{
            return 0;
        }
        
    }
};