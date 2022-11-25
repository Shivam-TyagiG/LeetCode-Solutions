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
    void solve(TreeNode* root,int targetsum,int sum,bool &ans)
    {
        if(root == NULL)
        {
            
            return ;
        }
        
        sum = sum+root->val;
        if(sum == targetsum && (root->left == NULL && root->right == NULL))
        {
            ans = true;
        }
        solve(root->left,targetsum,sum,ans);
        solve(root->right,targetsum,sum,ans);
        
    }
    
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
        {
            return false;
        }
        
        bool ans = false;
        solve(root,targetSum,0,ans);
        return ans;
        
    }
};