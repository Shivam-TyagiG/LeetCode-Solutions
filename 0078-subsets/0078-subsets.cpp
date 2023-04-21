class Solution {
public:
    void solve(vector<int>&nums, vector<int>& output, vector<vector<int>>& ans, int index){
        if(index==nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //not push
        solve(nums, output, ans, index+1);
        //push
        output.push_back(nums[index]);
        solve(nums, output, ans, index+1);
        output.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        solve(nums, output, ans, 0);
        return ans;
    }
};