#include<bits/stdc++.h>
class Solution {
private:
    void solve(string& digits, vector<string>& ans, string output, string mapping[], int index){
        if(index>=digits.length()){
            if(output.length()==0) return ;
            ans.push_back(output);
            return ;
        }
        
        int number = digits[index]-'0';
        
        for(int i=0; i<mapping[number].length(); i++){
            output.push_back(mapping[number][i]);
            solve(digits, ans, output, mapping, index+1);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; 
        vector<string> ans;
        string output="";
        int i=0;
        solve(digits, ans, output, mapping, i);
        return ans;
    }
};