//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    void reverse(string& s, int i, int j){
        while(i<=j){
            swap(s[i++], s[j--]);
        }
    }
    string reverseWords(string s) 
    { 
        // code here 
        int lastpos = 0, n=s.length()-1;
        for(int i=0; i<=n; i++){
            if(s[i]=='.'){
                reverse(s, lastpos, i-1);
                lastpos = i+1;
            }
        }
        // cout<<s[lastpos-1]<<" "<<s[n]<<'8'<<endl;;
        reverse(s, lastpos, n);
        reverse(s, 0, n);
        return s;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends