//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        void solve(string& s, vector<string>& ans, string output, int i){
            if(i>=s.length()){
                if(output.length()==0) return ;
                ans.push_back(output);
                return ;
            }
            //exclude
            solve(s, ans, output, i+1);
            //include
            output+=s[i];
            solve(s, ans, output, i+1);
}
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string output;
		    int i=0;
		    solve(s, ans, output, i);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends