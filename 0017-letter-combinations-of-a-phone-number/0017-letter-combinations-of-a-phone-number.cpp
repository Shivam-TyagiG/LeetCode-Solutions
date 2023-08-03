class Solution {
public:
     void solve(vector<string> &ans, string &output, string &s, string *arr, int i)
    {

        //Base Case
        if(i>=s.size()){
            ans.push_back(output);
            return ;
        }

        //Processing 
        int digit = s[i]-'0';
        string temp = arr[digit];
        for(int k=0; k<temp.length(); k++)
        {
            output.push_back(temp[k]);
            solve(ans, output,s, arr, i+1);
            output.pop_back();
        }

    }
    
    
    vector<string> letterCombinations(string digits) {
        
        //create a vector<string> type answer because it return type is vector<string>
        vector<string> ans;
        
        // if size of input digit is 0 then our outpur is empty so we return the empty vactor type string 
        if (digits.length()==0){
            return ans;
        }
        
        //every time we get a string which we want to store in the answer 
        //so we create a string type output
        string output;
        
        //we do mapping for 0 1 2 3 4 5 6 7 8 9 as shown below 
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        //index is present at starting 0 example:-
        //if digit is 2 then index 0 point a form "abc"
        int index=0;
        
        // now call a function upto length of string 
        //for(int i=0;i<digits.length();i++){
            solve(ans,output,digits,mapping, index);
        //}
        return ans;
        
    }
};