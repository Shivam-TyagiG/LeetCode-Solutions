//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long find_sum(int arr[], int n){
        long long sum = 0;
        for(int i=0; i<n; i++) sum+=arr[i];
        return sum;
    }
    
    bool possible(int arr[], int n, int k, long long mid){
        int count = 1;
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                count++;
                if(count>k || arr[i]>mid) return false;
                sum=arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long low = 0, high = find_sum(arr, n);
        long long ans = 0;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(possible(arr, n, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends