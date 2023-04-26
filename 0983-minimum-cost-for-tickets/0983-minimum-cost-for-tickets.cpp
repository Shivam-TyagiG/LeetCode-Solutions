class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        if(i>=days.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int option1 = costs[0]+solve(days, costs, i+1, dp);
        int option2;
        int j=i;
        for( ; j<days.size() && days[j]<days[i]+7; j++);
        option2 = costs[1]+solve(days, costs, j, dp);
        j=i;
        int option3;
        for( ; j<days.size() && days[j]<days[i]+30; j++);
        option3 = costs[2]+solve(days, costs, j, dp);
        return dp[i] = min(option1, min(option2, option3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i=0;
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(days, costs, i, dp);
        
    }
};