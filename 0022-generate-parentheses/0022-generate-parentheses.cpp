class Solution {
public:
    string output;
    vector<string> ans;
    void solve(int index, int open, int close, int n)
    {
        if((2*n)==index){
            ans.push_back(output);
            return ;
        }
        if(open==close){
            output+='(';
            solve(index+1, open+1, close, n);
            output.pop_back();
        }
        else if(open>close)
        {
            if(open==n){
                output+=')';
                solve(index+1, open, close+1, n);
                output.pop_back();
            }
            else{
                output+='(';
                solve(index+1, open+1, close, n);
                output.pop_back();
                output+=')';
                solve(index+1, open, close+1, n);
                output.pop_back();
            }
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        int index = 0;
        int open = 0;
        int close = 0;
        solve(index, open, close, n);
        return ans;
    }
};