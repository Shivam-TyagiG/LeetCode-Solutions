//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> ans;
        
        int size = q.size();
        int j = size/2;
        int i=0;
        
        queue<int> p;
        for( ; i<j; i++){
            p.push(q.front());
            q.pop();
        }
        i=0;
        while(i<j){
            ans.push_back(p.front());
            p.pop();
            ans.push_back(q.front());
            q.pop();
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends