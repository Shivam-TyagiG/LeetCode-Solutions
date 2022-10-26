//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> maxi(k);
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            while((!maxi.empty()) && (arr[maxi.back()]<=arr[i]))
            {
                maxi.pop_back();
            }
            maxi.push_back(i);
        }
        ans.push_back(arr[maxi.front()]);
        for(int i=k;i<n;i++)
        {
            while(!maxi.empty() && i-maxi.front()>=k)
            {
                maxi.pop_front();
            }
            while(!maxi.empty() && arr[maxi.back()]<=arr[i])
            {
                maxi.pop_back();
            }
            
            maxi.push_back(i);
            ans.push_back(arr[maxi.front()]);
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends