//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void solve(string s,int index, set<string> &ans)
    {
        //base case
        if(index>=s.length())
        {
            ans.insert(s);
            return ;
        }
        
        
        for(int i=index;i<s.length();i++)
        {
            swap(s[i],s[index]);
            solve(s,index+1,ans);
            swap(s[i],s[index]);
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		   int index=0;
		   set<string> ans;
		   
		   solve(S,index,ans);
		   int size = ans.size();
		   vector<string> v(size);
		   
		   copy(ans.begin(),ans.end(),v.begin());
		   sort(v.begin(),v.end());
		   return v;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends