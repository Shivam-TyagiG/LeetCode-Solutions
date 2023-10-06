//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    void find_prev(vector<long long>& prev, long long arr[], int n){
        stack<int> st;
        st.push(0);
        prev[0]=-1;
        for(int i=1; i<n; i++){
            long long  num = arr[i];
            while(!st.empty() && num<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()) prev[i]=-1;
            else prev[i] = st.top();
            st.push(i);
        }
    }
    
    void find_next(vector<long long>& next, long long arr[], int n){
        stack<int> st;
        st.push(n-1);
        next[n-1]=n;
        for(int i=n-2; i>=0; i--){
            long long  num = arr[i];
            while(!st.empty() && num<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()) next[i]=n;
            else next[i] = st.top();
            st.push(i);
        }
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> prev(n, -1);
        vector<long long> next(n, n);
        find_prev(prev, arr, n);
        find_next(next, arr, n);
        long long ans = 0;
        for(int i=0; i<n; i++){
            int length = next[i]-prev[i]-1;
            long long cmp = length*arr[i];
            ans = max(cmp, ans);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends