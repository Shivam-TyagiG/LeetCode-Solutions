//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool possible(int n, int k, vector<int>& arr, int mid){
        int count = 1;
        int lastcow = 0;
        for(int i=0; i<n; i++){
            if(arr[i]-arr[lastcow]>=mid){
                count++;
                if(count==k) return 1;
                lastcow = i;
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls[n-1]-stalls[0];
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(possible(n, k, stalls, mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends