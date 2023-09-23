//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int find_sum(int A[], int n){
        int sum =0 ;
        for(int i=0; i<n; i++){
            sum+=A[i];
        }
        return sum;
    }
    bool detect(int arr[], int& n, int& m, int mid){
        int count = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                count++;
                if(count>m || arr[i]>mid) return false;
                sum = arr[i];
            }
        }
        // if(count<m) return 0;
         return 1;
        
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M) return -1;
        int sum = find_sum(A, N);
        int low = 0, high = sum;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            // cout<<mid<<endl;
            bool possible = detect(A, N, M, mid);
            if(possible){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends