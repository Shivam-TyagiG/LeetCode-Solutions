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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0;
        int preEnd = preorder.size()-1;
        int inStart = 0;
        int inEnd = inorder.size()-1;
        return construct(preorder, inorder, preStart, preEnd, inStart, inEnd);
    }
};