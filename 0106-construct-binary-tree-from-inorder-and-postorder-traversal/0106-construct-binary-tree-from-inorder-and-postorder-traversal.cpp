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
    int find_index(vector<int>& in_order, int element, int i, int j){
        for(int k=i; k<=j; k++){
            if(in_order[k] == element) return k;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int& post_start, int& post_end)
    {
        if(in_start > in_end || post_start < post_end) return NULL;
        int element = postorder[post_start];
        post_start--;
        int index = find_index(inorder, element, in_start, in_end);
        TreeNode* root = new TreeNode(element);
        root->right = solve(inorder, postorder, index+1, in_end, post_start, post_end);
        root->left = solve(inorder, postorder, in_start, index-1, post_start, post_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_start = 0;
        int in_end = inorder.size()-1;
        int post_start = postorder.size()-1;
        int post_end = 0;
        return solve(inorder, postorder, in_start, in_end, post_start, post_end);
        
    }
};