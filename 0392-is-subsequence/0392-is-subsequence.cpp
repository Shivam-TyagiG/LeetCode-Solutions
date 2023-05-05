class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k=0;
        for(int i=0; i<t.length(); i++){
            if(s[k]==t[i]) k++;
            if(k==s.length()) return 1;
        }
        if(k==s.length()) return 1;
        return 0;
    }
};