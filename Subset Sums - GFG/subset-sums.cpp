//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
private:
    void solve(vector<int>& arr, vector<int>& ans, int n, int i, int sum){
        if(i>=n) {
            ans.push_back(sum);
            return ;
        }
        
        //include
        sum+=arr[i];
        solve(arr, ans, n, i+1, sum);
        //exclude
        sum-=arr[i];
        solve(arr, ans, n, i+1, sum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        int i=0;
        solve(arr, ans, N, i, 0);
        return ans;
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
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends