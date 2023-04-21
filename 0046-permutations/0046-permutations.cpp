class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>>& ans, int size, int index){
        if(index==size-1){
            ans.push_back(nums);
            return ;
        }
        
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(nums, ans, size, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        int index = 0;
        solve(nums, ans, size, index);
        return ans;
    }
};