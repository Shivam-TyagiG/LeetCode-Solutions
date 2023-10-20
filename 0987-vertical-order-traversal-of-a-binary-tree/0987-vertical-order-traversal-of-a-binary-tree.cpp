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
        map<int, map<int,vector<int>> > m;
        queue<pair<int,pair<int,TreeNode*>>> q;
        if(root==NULL)  return ans;
        q.push({0,{0, root}});
        while(!q.empty()){
            pair<int,pair<int,TreeNode*>> front = q.front();
            q.pop();
            int hd = front.first;
            int level = front.second.first;
            TreeNode* node = front.second.second;
            m[hd][level].push_back(node->val);
            if(node->left) q.push({hd-1,{level+1, node->left}});
            if(node->right) q.push({hd+1,{level+1, node->right}});
        }
        for(auto i:m){
            vector<int> output;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k:j.second){
                    // ans.push_back(k);
                    // ans.push_back(j.second);
                    output.push_back(k);
                }
            }
            // sort(output.begin(), output.end());
            ans.push_back(output);
        }
        return ans;
    }
};