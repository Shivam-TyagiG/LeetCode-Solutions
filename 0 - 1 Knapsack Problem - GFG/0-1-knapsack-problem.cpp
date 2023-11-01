//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int solve(int capacity, int wt[], int val[], int index, vector<vector<int>>& dp){
        if(index == 0){
            if(capacity>=wt[0]) return val[0];
            else return 0;
        }
        if(dp[index][capacity]!=-1) return dp[index][capacity];
        //exclude
        int exc = 0 + solve(capacity, wt, val, index-1, dp);
        //include
        int inc = 0;
        if(capacity>=wt[index]) inc = val[index] + solve(capacity-wt[index], wt, val, index-1, dp);
        dp[index][capacity] = max(exc, inc);
        return max(exc, inc);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   int ans = solve(W, wt, val, n-1);
    //   return ans;
        
        
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        int ans = solve(W, wt, val, n-1, dp);
        return ans;
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends