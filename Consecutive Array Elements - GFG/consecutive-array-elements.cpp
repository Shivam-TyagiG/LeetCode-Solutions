//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	
	
	public:
	bool areConsecutives(long long arr[], int n) 
	{ 
	    // Your code goes here
	    long long mini = LLONG_MAX;
	    long long ans = 0;
	    for(int i=0; i<n; i++){
	        mini = min(mini, arr[i]);
	    }
	    
	    for(long long i = mini; i<mini+n; i++){
	        ans = ans^i^arr[i-mini];
	    }
	    if(ans == 0) return 1;
	    return 0;
	}
		 

};
	 

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    long long a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       
        Solution ob;
        if(ob.areConsecutives(a, n) == true)
	        cout<<"Yes";
	    else
	        cout<<"No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends