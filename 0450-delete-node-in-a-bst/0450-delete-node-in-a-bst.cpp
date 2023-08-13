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
    TreeNode* find_mini(TreeNode* head){
        while(head->left!=NULL){
            head=head->left;
        }
        return head;
    }
    

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL && root->right==NULL){
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            else if(root->right!=NULL && root->left==NULL){
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            else if(root->right!=NULL && root->left!=NULL){
                TreeNode* mini = find_mini(root->right);
                root->val = mini->val;
                root->right = deleteNode(root->right, mini->val);
            }
        }
        
        if(root->val<key){
            root->right = deleteNode(root->right, key);
        }
        else{
            root->left = deleteNode(root->left, key);
        }
        return root;
        
    }
};