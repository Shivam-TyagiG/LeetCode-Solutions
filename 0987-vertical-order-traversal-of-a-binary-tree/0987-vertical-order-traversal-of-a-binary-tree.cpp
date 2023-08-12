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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        
        vector<int> output;
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, vector<int>>> m;
        q.push({root,{0, 0}});
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<TreeNode*, pair<int,int>> front = q.front();
                q.pop();
                TreeNode* node = front.first;
                int hd = front.second.first;
                int level = front.second.second;
                m[hd][level].push_back(node->val);
                if(node->left) q.push({node->left, {hd-1, level+1}});
                if(node->right) q.push({node->right, {hd+1, level+1}});
            }
        }
        
        for(auto i:m){
            vector<int> output;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k:j.second){
                    output.push_back(k);
                }
            }
            ans.push_back(output);
        }
        return ans;
        
    }
};