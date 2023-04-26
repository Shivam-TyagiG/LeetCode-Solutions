class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i==nums.size()) return 0;
        if(j!=-1 && dp[i][j]!=-1) return dp[i][j];
        int include = 0;
        if(j==-1||nums[i]>nums[j]) include=1+solve(nums, i+1, i, dp);
        int exclude = solve(nums, i+1, j, dp);
        if(j!=-1) dp[i][j]=max(include, exclude);
        return max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int i=0, j=-1;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(nums, i, j, dp);
        
    }
};