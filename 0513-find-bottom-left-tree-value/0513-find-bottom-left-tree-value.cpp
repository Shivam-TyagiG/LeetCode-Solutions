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
    void solve(TreeNode* root, int lvl, int hd, int& maxlvl, int& maxhd, int& ans){
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            if(maxlvl == 0){
                maxlvl = lvl;
                ans = root->val;
            }
            else if(lvl > maxlvl){
                ans = root->val;
                maxlvl = lvl;
            }
        }
        
        solve(root->left, lvl+1, hd-1, maxlvl, maxhd, ans);
        solve(root->right, lvl+1, hd+1, maxlvl, maxhd, ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int lvl = 0;
        int hd = 0;
        int ans = -1;
        int maxlvl = 0;
        int maxhd = 0;
        solve(root, lvl, hd, maxlvl, maxhd, ans);
        return ans;
        
    }
};