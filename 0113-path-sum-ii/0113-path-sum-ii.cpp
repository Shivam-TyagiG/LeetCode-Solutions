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
    void solve(TreeNode* root, int& targetSum, int sum, vector<vector<int>>& ans, vector<int> output){
        if(root==NULL){
            return ;
        }
        output.push_back(root->val);
        sum+=root->val;
        if(sum==targetSum && !root->left && !root->right) ans.push_back(output);
        solve(root->left, targetSum, sum, ans, output);
        solve(root->right, targetSum, sum, ans, output);
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> output;
        solve(root, targetSum, sum, ans, output);
        return ans;
    }
};