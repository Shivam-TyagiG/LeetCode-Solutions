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
    pair<int, int> solve(TreeNode* root){
        if(root == NULL) return {0, 0};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int left_dia = left.first;
        int right_dia = right.first;
        int curr_dia = left.second + right.second + 1;
        return {max(curr_dia, max(left_dia, right_dia)), max(left.second, right.second)+1};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first - 1;
    }
};