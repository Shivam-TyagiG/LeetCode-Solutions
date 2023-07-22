//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int solve(int arr[], int low, int high, int k){
        if(high<low) return -1;
        int mid = low+high;
        if(arr[mid]==k) return mid;
        else if(arr[mid]<k) return solve(arr, mid+1, high, k);
        else return solve(arr, low, mid-1, k);
    }
    int binarysearch(int arr[], int n, int k) {
        // code here
        int l=0;
        int high=n-1;
        return solve(arr, l, high, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends