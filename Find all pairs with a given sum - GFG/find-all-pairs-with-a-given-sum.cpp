//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int k, int n){
        int i=0, j=n-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid] == k) return mid;
            else if(arr[mid] < k) i=mid+1;
            else j=mid-1;
        }
        return -1;
        
    }
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here 
        vector<pair<int,int>> ans;
        sort(A, A+N);
        sort(B, B+M);
        int i=0, j=0;
        int sum = 0;
        
        for(int i=0; i<N; i++){
            int find = X-A[i];
            int pos = search(B, find, M);
            if(pos != -1){
                ans.push_back({A[i], B[pos]});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends