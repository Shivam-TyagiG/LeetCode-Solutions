//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_map<int,int> m;
        int ans = 0;
        for(int i=0; i<N; i++){
            if(m.find(arr[i])!=m.end()) continue;
            int ls = 0, rs = 0;
            if(m.find(arr[i]-1)!=m.end()) ls = m[arr[i]-1];
            if(m.find(arr[i]+1)!=m.end()) rs = m[arr[i]+1];
            m[arr[i]] = 1+ls+rs;
            ans = max(ans, m[arr[i]]);
            m[arr[i]-ls] = m[arr[i]];
            m[arr[i]+rs] = m[arr[i]];
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends