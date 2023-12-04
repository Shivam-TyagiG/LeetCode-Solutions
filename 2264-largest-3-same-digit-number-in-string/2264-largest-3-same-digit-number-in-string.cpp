class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length()-1;
        string ans = "";
        for(int i=n; i>=2; i--){
            string s = num.substr(i-2, 3);
            bool check = true;
            for(int j=1; j<s.length(); j++){
                if(s[j]!=s[j-1]){
                    check = false;
                    break;
                }
            }
            if(check){
                ans = max(ans, s);
            }
        }
        return ans;
    }
};