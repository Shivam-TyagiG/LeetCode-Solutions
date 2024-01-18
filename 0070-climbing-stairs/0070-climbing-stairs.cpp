class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n==0 || n==1) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n] = climbStairs(n-1)+climbStairs(n-2);
        return dp[n];
    }
    int solve1(int n, vector<int>& dp){
        dp[0]=1;
        dp[1]=1;
        if(n<=1) return 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int solve2(int n, vector<int>& dp){
        int prev_prev = 1;
        int prev = 1;
        if(n<=1) return 1;
        for(int i=2; i<=n; i++){
            int curr = prev + prev_prev;
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        // return solve(n, dp);
        // return solve1(n, dp);
        return solve2(n, dp);
    }
};