//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool possible(int n, int k, vector<int> &stalls, int mid){
        int count = 1;
        int previous=0;
        for(int i=0; i<n; i++){
            if( stalls[i]-stalls[previous] >= mid){
                previous=i;
                count++;
                if(count==k) return 1;
            }
        }
        return 0;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        int l=0, h=1e9+1;
        int maximum_space = -1;
        sort(stalls.begin(), stalls.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(n, k, stalls, mid)){
                l=mid+1;
                maximum_space=mid;
            }
            else{
                h = mid-1;
            }
        }
        
        return maximum_space;
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