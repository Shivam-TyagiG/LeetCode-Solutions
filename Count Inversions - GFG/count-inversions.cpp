//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count in
    void conquer(long long arr[], long long low, long long mid, long long high){
    long long i=low, j=mid+1;
    vector<long long> temp;
    while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                
                temp.push_back(arr[i++]);
            }
            else{
                count+=mid-i+1;
                temp.push_back(arr[j++]);
            }
        }
        while(i<=mid){
            
            temp.push_back(arr[i++]);
        }
        
        while(j<=high){

            temp.push_back(arr[j++]);
        }
    
        for(i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
    }
    
    void divide(long long nums[], long long low, long long high){
        if(low>=high) return ;
        int mid = low+(high-low)/2;
        divide(nums, low, mid);
        divide(nums, mid+1, high);
        conquer(nums, low, mid, high);
    }
    long long int count=0;
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long low = 0, high = n-1;
        divide(arr,  low, high);
        return count;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends