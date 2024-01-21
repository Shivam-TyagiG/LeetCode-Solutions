class Solution {
public:
    int solve(vector<int>& nums, int& n, int i, vector<int>& dp){
        if(i==n) return nums[i];
        if(i>n) return 0;

        //
        if(dp[i]!=-1) return dp[i];
        //include
        int inc = solve(nums, n, i+2, dp)+nums[i];
        int exc = solve(nums, n, i+1, dp);
        dp[i]=max(inc, exc);
        return dp[i];
    }
    int rob(vector<int>& nums) {
       
        int n = nums.size()-1;
        vector<int> dp(n,-1);
        int bhejo=n-1;
        int first = solve(nums, bhejo, 0, dp);
        dp.clear();
        vector<int> sd(n,-1);
        int second = solve(nums, n, 0, sd);
        return max(first,second);
    }
};