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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, int>> s;
        if(root==NULL) return ans;
        s.push({root, 0});
        while(!s.empty()){
            pair<TreeNode*, int> top = s.top();
            s.pop();
            if(top.second == 0){
                if(top.first->right) s.push({top.first->right, 0});
                s.push({top.first  ,1});
                if(top.first->left) s.push({top.first->left, 0});
            }
            else{
                ans.push_back(top.first->val);
            }
        }
        return ans;
    }
};