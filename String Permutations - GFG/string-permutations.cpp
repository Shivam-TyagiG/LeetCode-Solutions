//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int i, vector<string>& ans, string& output)
    {
        if(i>=output.length()){
            ans.push_back(output);
        }
        
        for(int k=i; k<output.size(); k++){
            swap(output[i], output[k]);
            solve(i+1, ans, output);
            swap(output[i], output[k]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        solve(0, ans, S);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends