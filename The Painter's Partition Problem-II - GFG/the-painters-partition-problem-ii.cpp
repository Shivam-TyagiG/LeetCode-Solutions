//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    private:
        bool possible(int arr[], long long n, long long  k, long long  mid){
            long long  sum = 0;
            long long count = 1;
            for(long long i=0; i<n; i++){
                if(sum+arr[i]<=mid){
                    sum+=arr[i];
                }
                else{
                    count++;
                    if(count>k||arr[i]>mid) return 0;
                    sum=arr[i];
                }
            }
            return 1;
        }
  public:
    long long minTime(int arr[], int n, int k)
    {
        // code here
        long long l=0, h=0;
        for(long long i=0; i<n; i++){
            h+=arr[i];
        }
        long long minimum_time=-1;
        while(l<=h){
            long long  mid = l+(h-l)/2;
            if(possible(arr, n, k, mid)){
                minimum_time=mid;
                h=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return minimum_time;
        // return minimum time
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