//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

const int mod = 1e9+7;
class Solution{
    private:
        long long solve(int n, int k){
            if(n==0) return 0;
            if(n==1) return k;
            if(n==2) return (k+(k*(k-1)%mod)%mod)%mod;
            return (solve(n-2, k)%mod*(k-1)%mod + solve(n-1, k)%mod*(k-1)%mod)%mod;
        }
        long long solve1(int n, int k, vector<int>& dp){
            if(n==0) return 0;
            if(n==1) return k;
            if(n==2) return (k+(k*(k-1)%mod)%mod)%mod;
            if(dp[n]!=-1) return dp[n];
            dp[n] = (solve1(n-2, k, dp)%mod*(k-1)%mod + solve1(n-1, k, dp)%mod*(k-1)%mod)%mod;
            return dp[n];
        }
        long long solve2(int n, int k, vector<long long int>& dp){
            dp[0] = 0;
            dp[1] = k;
            dp[2] = (k + (k*(k-1)%mod)%mod)%mod;
            for(int i=3; i<=n; i++){
                dp[i] = ((dp[i-2]*(k-1)%mod)%mod + (dp[i-1]*(k-1)%mod)%mod)%mod;
            }
            return dp[n];
        }
    public:
    long long countWays(int n, int k){
        // code here
        // return solve(n, k);
        vector<long long int> dp(n+2, -1);
        return solve2(n, k, dp);
        
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends