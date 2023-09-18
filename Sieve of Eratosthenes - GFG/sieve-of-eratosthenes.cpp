//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<bool> p(N+1, true);
        for(int i=2; i<N; i++){
            if(p[i]){
                int k=i;
                for(int j=i+k; j<=N; j=j+k){
                    p[j]=false;
                }
            }
        }
        vector<int> ans;
        for(int i=2; i<=N; i++){
            if(p[i]==true) ans.push_back(i);
        }
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
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends