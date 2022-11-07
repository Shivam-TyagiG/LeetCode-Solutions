//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool issafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> m)
    {
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y]==1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    private:
    void solve(vector<string> &ans,vector<vector<int>> &m,string output,int i,int j,int n,vector<vector<int>> visited )
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(output);
            return ;
        }
        visited[i][j]=1;
        //4 choice-D,L,R,U
        //Down
        int newi = i+1;
        int newj = j;
        if(issafe(newi,newj,n,visited,m))
        {
            output.push_back('D');
            solve(ans,m,output,newi,newj,n,visited);
            output.pop_back();
        }
        //left
        newi = i;
        newj = j-1;
        if(issafe(newi,newj,n,visited,m))
        {
            output.push_back('L');
            solve(ans,m,output,newi,newj,n,visited);
            output.pop_back();
        }
        
        //right
        newi = i;
        newj = j+1;
        if(issafe(newi,newj,n,visited,m))
        {
            output.push_back('R');
            solve(ans,m,output,newi,newj,n,visited);
            output.pop_back();
        }
        
        //up
        newi = i-1;
        newj = j;
        if(issafe(newi,newj,n,visited,m))
        {
            output.push_back('U');
            solve(ans,m,output,newi,newj,n,visited);
            output.pop_back();
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0)
        {
            return ans;
        }
        string output = "";
        int i=0,j=0;
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        solve(ans,m,output,i,j,n,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends