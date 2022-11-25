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
    private:
    void solve(TreeNode* root,int &sum)
    {
        if(root == NULL)
        {
            return ;
        }
        
        solve(root->left,sum);
        solve(root->right,sum);
        if(root->left != NULL && root->left->right == NULL && root->left->left == NULL)
        {
            cout<<root->left->val<<" ";
            sum = sum+root->left->val;
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return sum;
        
    }
};