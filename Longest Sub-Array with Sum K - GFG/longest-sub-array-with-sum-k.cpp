//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        int maxi = 0;
        for(int i=0; i<N; i++){
            sum+=A[i];
            if(m.find(sum-k)!=m.end()){
                maxi = max(maxi, i-m[sum-k]);
            }
            if(m.find(sum)==m.end()) m[sum] = i;
        }
        return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends