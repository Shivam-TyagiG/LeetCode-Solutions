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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        int maxsum = INT_MIN;
        int count =0;
        int ans = 0;
        while(!q.empty())
        {
            count++;
            int sum = 0;
            int size = q.size();
            for(int i=size-1;i>=0;i--)
            {
                TreeNode* frontnode = q.front();
                q.pop();
                sum=sum+frontnode->val;
                if(frontnode->left != NULL)
                {
                    q.push(frontnode->left);
                }
                if(frontnode->right != NULL)
                {
                    q.push(frontnode->right);
                }
                
                
            }
            if(sum>maxsum)
            {
                ans = count;
                maxsum = sum;
            }
        }
        return ans;
    }
};