class Solution {
    int mod = 1e9+7;
    private:
    long long solve(int n, int k, int target, vector<vector<long long>>& dp){
        if(n==0 || target<0){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
        
//         for k faces
        long long ans = 0; 
        for(int i=1; i<=k; i++){
            ans = (ans+solve(n-1, k, target-i, dp))%mod;
        }
        return dp[n][target] = ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return solve(n, k, target, dp)%mod;
    }
};