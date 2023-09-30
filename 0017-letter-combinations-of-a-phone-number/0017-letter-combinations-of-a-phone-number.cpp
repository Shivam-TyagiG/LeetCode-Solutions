class Solution {
public:
    void solve(string& digits,string& output, vector<string>& ans, string mapping[], int index){
        if(index>=digits.size()){
            if(output.length()==0) return; 
            ans.push_back(output);
            return ;
        }
        
        int digit = digits[index]-'0';
        string value = mapping[digit];
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, ans, mapping, index+1);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, ans, mapping, 0);
        return ans;
    }
};