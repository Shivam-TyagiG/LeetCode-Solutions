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
void leaf(TreeNode* root, vector<int>& ans){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            return ;
        }
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        leaf(root1, ans1);
        leaf(root2, ans2);
        int n = ans1.size();
        int m = ans2.size();
        if(n != m) return false;
        for(int i=0; i<n; i++){
            if(ans1[i] != ans2[i]) return false;
        }
        return 1;
    }

};