class Solution {
public:
    int recursion(vector<int>& coins, int amount){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        int ans=INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int temp = recursion(coins, amount-coins[i]);
            if(temp!=INT_MAX) ans = min(ans, 1+temp);
        }
        return ans;
        
    }
    
    int recursion_memoization(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int ans=INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int temp = recursion_memoization(coins, amount-coins[i], dp);
            if(temp!=INT_MAX){
                ans = min(ans, 1+temp); 
            }
        }
        dp[amount]=ans;
        return ans;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = recursion(coins, amount);
        vector<int> dp(amount+1, -1);
        int ans = recursion_memoization(coins, amount, dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};