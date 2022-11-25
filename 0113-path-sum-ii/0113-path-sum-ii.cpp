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
    void solve(TreeNode* root, vector<vector<int>> &ans,vector<int> path,int targetsum,int sum)
    {
        if(root == NULL)
        {
            return;
        }
        path.push_back(root->val);
        sum = sum+root->val;
        if(root->left == NULL  &&  root->right == NULL && sum == targetsum)
        {
            
            ans.push_back(path);
        }
        solve(root->left,ans,path,targetsum,sum);
        solve(root->right,ans,path,targetsum,sum);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        solve(root,ans,path,targetsum,sum);
        return ans;
        
    }
};