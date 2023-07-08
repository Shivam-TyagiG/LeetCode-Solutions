//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
        {
            // Your code goes here
            long long ans = INT_MIN;
            long long sum=0;
            sum+=arr[0]+arr[1];
            ans=sum;
            for(int i=2; i<N; i++){
                sum+=arr[i];
                sum-=arr[i-2];
                ans=max(sum, ans);
            }
            return ans;
        }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends