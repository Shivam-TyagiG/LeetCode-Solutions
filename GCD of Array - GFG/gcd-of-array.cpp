//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int find(int a, int b){
	    int mini = min(a,b);
	    int maxi = max(a,b);
	    while(maxi%mini!=0){
	        int temp = maxi; 
	        maxi = mini;
	        mini = temp%mini;
	    }
	    return mini;
	}
    int gcd(int N, int arr[])
    {
    	// Your code goes here
    	if(N<2) return arr[0];
    	int gcdi = find(arr[0], arr[1]);
    	for(int i=2; i<N; i++){
    	    gcdi = find(gcdi,arr[i]);
    	}
    	return gcdi;
    }
};


//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}
// } Driver Code Ends