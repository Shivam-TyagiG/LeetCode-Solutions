//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool issafe(vector<vector<int>> &m, vector<vector<int>> &mapping, int& n, int x, int y){
        if(x>=0 && y>=0 && x<n && y<n && mapping[x][y]==0 && m[x][y]==1) return 1;
        return 0;
    }
    void solve(vector<vector<int>> &m, vector<vector<int>> &mapping, int& n, int newx[], int newy[], int x, int y, vector<string>& ans, string& output, char pos[]){
        
        if(x==n-1 && y==n-1){
            ans.push_back(output);
            return ;
        }
        if(x>=n || y>=n) return ;
        mapping[x][y] = 1;
        for(int i=0; i<4; i++){
            if(issafe(m, mapping, n, x+newx[i], y+newy[i])){
                output.push_back(pos[i]);
                solve(m, mapping, n, newx, newy, x+newx[i], y+newy[i], ans, output, pos);
                output.pop_back();
            }
        }
        mapping[x][y]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int newx[4] = {1, -1, 0, 0};
        int newy[4] = {0, 0, -1, +1};
        char pos[4] = {'D', 'U', 'L', 'R'};
        vector<string> ans;
        if(m[0][0]==0) return ans;
        string output = "";
        int x = 0;
        int y = 0;
        vector<vector<int>> mapping(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mapping[i][j]=0;
            }
        }
        solve(m, mapping, n, newx, newy, x, y, ans, output, pos);
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