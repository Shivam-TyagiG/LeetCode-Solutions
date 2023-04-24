class Solution {
public:
    int recusrsion(int n, vector<int>& cost){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        int ans1 = recusrsion(n-1, cost);
        int ans2 = recusrsion(n-2, cost);
        int ans = min(ans1, ans2)+cost[n];
        return ans;
    }
    int recursion_memoization(int n, vector<int>& cost, vector<int>& dp){
        if(n==0) return cost[0];
        if(n==1) return cost[1];
        if(dp[n]!=-1) return dp[n];
        int ans1 = recursion_memoization(n-1, cost, dp);
        int ans2 = recursion_memoization(n-2, cost, dp);
        int ans = min(ans1, ans2)+cost[n];
        dp[n]= ans;
        return ans;
    }
    int bottom_up(vector<int>& cost){
        //In this approach the Base case of recursive approach fixed at starting 
        //first base case when we at stair 0 cost is 0
        //second base case when we at stair 1 cost is 1
        int n=cost.size();
        vector<int> dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        //now dp kha se kha tk chal rhi ha vha se vha tk for loop lga do 
        for(int i=2; i<n; i++){
            //dp vale ans ki same line chipka do 
            dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //Call for bottom_up approach
        return bottom_up(cost);
        
        //call for recursion+memoization approach
        int n=cost.size();
        vector<int> dp(n,-1);
        //return min(recursion_memoization(n-1, cost, dp), recursion_memoization(n-2, cost, dp));
    }
};