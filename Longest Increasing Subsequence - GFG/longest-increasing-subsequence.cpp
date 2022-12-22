//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve(int n, int a[])
    {
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        for(int cur=n-1; cur>=0; cur--)
        {
            for(int pre = cur-1; pre>=-1; pre--)
            {
                int take = 0;
                if(pre == -1 || a[cur]>a[pre])
                {
                    take = 1 + next[cur+1];
                }
                int nottake = next[pre+1];
                curr[pre+1] = max(take,nottake);
            }
            next = curr;
        }
        return next[0];
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code 
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n, a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends