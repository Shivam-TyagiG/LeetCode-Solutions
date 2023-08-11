class Solution {
private:
    void solve(vector<int> output, vector<int>& nums, vector<vector<int>>&ans, int i){
        if(i>=nums.size()){
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(output, nums, ans, i+1);
        //include
        output.push_back(nums[i]);
        solve(output, nums, ans, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int i=0;
        solve(output, nums, ans, i);
        return ans;
    }
};