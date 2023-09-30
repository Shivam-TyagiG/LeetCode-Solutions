//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(string& s, string& output, vector<string>& ans, int i){
	    if(i>=s.length()){
	        if(output.length()==0) return ;
	        ans.push_back(output);
	        return ;
	    }
	    //exclude
	    solve(s, output, ans, i+1);
	    //include
	    output.push_back(s[i]);
	    solve(s, output, ans, i+1);
	    output.pop_back();
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string output="";
		    vector<string> ans;
		    solve(s, output, ans, 0);
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