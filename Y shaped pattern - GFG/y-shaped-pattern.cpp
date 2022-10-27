//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    vector<string> yShapedPattern(int N) {
        
        vector<string> ans;
        
        for(int i=0;i<N/2;i++)
        {
            string s = "";
            for(int j=0;j<i;j++)
            {
                s=s+" ";
            }
            s = s + "*";
            int n;
            if(N%2 != 0)
            {
                n=N-1;
            }
            else{
                n=N;
            }
            for(int j=n-(2*i+1);j>0;j--)
            {
                s=s + " ";
            }
            s=s + "*";
            
            ans.push_back(s);
        }
        string s="";
        for(int i=0;i<N/2;i++)
        {
            s=s+" ";
        }
        s=s+"*";
        for(int i=0;i<N/2;i++)
        {
            s=s+" ";
        }
        if(N%2 != 0)
        {
            ans.push_back(s);
        }
        for(int i=0 ; i<N/2 ;i++)
        {
            ans.push_back(s);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<string> v = ob.yShapedPattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}
// } Driver Code Ends