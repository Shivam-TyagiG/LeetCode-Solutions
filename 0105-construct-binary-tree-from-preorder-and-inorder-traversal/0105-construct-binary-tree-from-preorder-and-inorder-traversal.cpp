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
    int find_position(int element, vector<int>& in){
        for(int i=0; i<in.size(); i++){
            if(in[i]==element) return i;
        }
        return -1;
    }
    TreeNode* construct(vector<int>& pre, vector<int>& in, int& preStart, int& preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart>inEnd) return NULL;
        int element = pre[preStart];
        preStart++;
        TreeNode* root = new TreeNode(element);
        int position = find_position(element, in);
        root->left = construct(pre, in, preStart, preEnd, inStart, position-1);
        root->right = construct(pre, in, preStart, preEnd, position+1, inEnd);
        return root;
    }
    
    int find_index(int element, vector<int>& inorder, int in_start, int in_end){
        for(int i=in_start; i<=in_end; i++){
            if(element == inorder[i]) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& pre_start, int& pre_end, int in_start, int in_end){
        if(pre_start>pre_end || in_start>in_end) return NULL;
        int element = preorder[pre_start];
        pre_start++;
        int index = find_index(element, inorder, in_start, in_end);
        TreeNode* root = new TreeNode(element);
        root->left = solve(preorder, inorder, pre_start, pre_end, in_start, index-1);
        root->right = solve(preorder, inorder, pre_start, pre_end, index+1, in_end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // int preStart = 0;
        // int preEnd = preorder.size()-1;
        // int inStart = 0;
        // int inEnd = inorder.size()-1;
        // return construct(preorder, inorder, preStart, preEnd, inStart, inEnd);
        
        //construct tree
        int pre_start = 0;
        int pre_end = preorder.size()-1;
        int in_start = 0;
        int in_end = inorder.size()-1;
        return solve(preorder, inorder, pre_start, pre_end, in_start, in_end);
        
    }
};