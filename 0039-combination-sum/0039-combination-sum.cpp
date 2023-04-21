class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& path, int& index, int curr, int& sum){
        if(curr==nums.size()){
            index++;
            return ;
        }
        if(sum==target){
            ans.push_back(path);
            return ;
        }
        if(sum>target){
            // index++;
            return ;
        }
        
        for(int i=index; i<nums.size(); i++)
        {
            sum+=nums[i];
            //cout<<sum<<endl;
            path.push_back(nums[i]);
            solve(nums, target, ans, path, i, i,sum);
            sum-=nums[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int index = 0;
        int sum = 0;
        solve(candidates, target, ans, path, index, 0, sum);
        return ans;
    }
};