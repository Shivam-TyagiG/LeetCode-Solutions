class Solution {
public:
    int solve(int n, vector<int>& cost, vector<int>& dp){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        if(dp[n]!=-1) return dp[n];
        int ans1 = solve(n-1, cost, dp);
        int ans2 = solve(n-2, cost, dp);
        int ans = min(ans1, ans2)+cost[n];
        dp[n]= ans;
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
};