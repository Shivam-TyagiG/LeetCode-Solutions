class Solution {
public:
    int solve(int i, int j, vector<int>& values, vector<vector<int>>& dp){
        if(i+1==j) return 0;
        int ans = INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i+1; k<j; k++){
            ans = min(ans, values[i]*values[j]*values[k]+solve(i,k, values, dp)+solve(k,j, values, dp));
            dp[i][j]=ans;
        }
        return ans;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int j=values.size();
        vector<vector<int>> dp(j, vector<int> (j,-1));
        return solve(0, j-1, values, dp);
    }
};