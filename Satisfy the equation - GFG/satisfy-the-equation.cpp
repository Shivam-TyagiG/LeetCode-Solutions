//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        map<pair<int,int>,int> mp;

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int sum=A[i]+A[j];
            mp[{i,j}]=sum;
        }
    }

    for(auto x1:mp){
        for(auto x2:mp){
            if(x1.second==x2.second && x1.first.first!=x2.first.first && x1.first.second!=x2.first.second && x1.first.second!=x2.first.first && x1.first.first!=x2.first.second){
                return {x1.first.first,x1.first.second,x2.first.first,x2.first.second};
            }
        }
    }

    return {-1,-1,-1,-1};

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends