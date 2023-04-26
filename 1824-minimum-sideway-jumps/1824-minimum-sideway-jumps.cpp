class Solution {
public:
//     int solve(vector<int>& obstacles, int currlane, int currposition, int &n, vector<vector<int>> &dp)
//     {
//         //base case 
//         if(currposition == n){
//             return 0;
//         }

//         //two case we can move in the same line 
//         if(obstacles[currposition+1] != currlane)
//         {
//             return solve(obstacles, currlane, currposition+1, n, dp);
//         }
//         if(dp[currlane][currposition]!=-1)
//         {
//             return dp[currlane][currposition];
//         }
//         else{
//             int ans = INT_MAX;
//             for(int i=1; i<=3; i++)
//             {
//                 //now we need to jump in side
//                 //so we check at same position ki kon si lane khali ha
//                 if(currlane!=i && obstacles[currposition]!=i)
//                 {
//                     ans = min(ans, 1+solve(obstacles, i, currposition, n, dp));
//                 }
//             }
//             return dp[currlane][currposition]=ans;
//         }
//     }
    
    
    /*
    
    //  Recursive accproach
    
    int solve(int currlane, int currpos, int& n, vector<int>& obstacles){
        if(currpos==n) return 0;
        
        if(obstacles[currpos+1]!=currlane){
            return solve(currlane, currpos+1, n, obstacles);
        }
        else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans, 1+solve(i, currpos, n, obstacles));
                }
            }
            return ans;
        }
    }
    
    */
    
    int solve_memoization(int currlane, int currpos, int& n, vector<int>& obstacles, vector<vector<int>>& dp){
        if(currpos==n) return 0;
        
        if(dp[currlane][currpos]!=-1) return dp[currlane][currpos];
        
        if(obstacles[currpos+1]!=currlane){
            return dp[currlane][currpos] = solve_memoization(currlane, currpos+1, n, obstacles , dp);
        }
        
        else{
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(currlane!=i && obstacles[currpos]!=i){
                    ans=min(ans, 1+solve_memoization(i, currpos, n, obstacles, dp));
                }
            }
            return dp[currlane][currpos] = ans;
        }
    }
    
    int minSideJumps(vector<int>& obstacles) {
        
        /* //Recursive Call
        int n=obstacles.size();
        int i=0; 
        return solve(2, i, n, obstacles);
        */
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solve_memoization(2, 0, n, obstacles,dp);
    }
};