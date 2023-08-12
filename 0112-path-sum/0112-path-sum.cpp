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
    void solve(TreeNode* root, int target, int sum, bool& flag){
        if(root==NULL) return ;
        sum+=root->val;
        if(sum==target && root->left==NULL && root->right==NULL){
            flag = true;
        }
        solve(root->left, target, sum, flag);
        solve(root->right, target, sum, flag);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool flag = false;
        solve(root, targetSum, sum, flag);
        return flag;
    }
};