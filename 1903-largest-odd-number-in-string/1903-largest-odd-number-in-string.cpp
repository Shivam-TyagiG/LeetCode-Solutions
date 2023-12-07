class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        for(int i=num.length()-1; i>=0; i--){
            int ele = num[i]-'0';
            if(ele%2 != 0 ){
                return num.substr(0, i+1);
            }
        }
        return ans;
    }
    
};