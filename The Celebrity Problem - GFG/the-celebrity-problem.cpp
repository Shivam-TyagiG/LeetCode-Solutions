//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        /*
        
        //Approach 1 
        //the celibrity is one who have all element in a row is 0 and in column 1 except itself 
        for(int i=0; i<n; i++){
            bool possible = 1;
            for(int j=0; j<n; j++){
                if(M[i][j]==1){
                    possible=0;
                    break;
                }
            }
            if(possible){
                for(int k=0; k<n; k++){
                    if(k==i) continue;
                    if(M[k][i]==0){
                        possible = 0;
                    }
                }
            }
            
            if(possible) return i;
        }
        return -1;
        
        */
        
        
        stack<int> s;
        for(int i=0; i<n; i++) s.push(i);
        
        while(s.size()>1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(M[a][b]) s.push(b);
            else s.push(a);
        }
        
        int top = s.top();
        for(int i=0; i<n; i++){
            if(M[top][i]==1) return -1;
            if(i!=top && M[i][top]==0) return -1;
        }
        
        return top;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends