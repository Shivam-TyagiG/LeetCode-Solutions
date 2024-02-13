class Solution {
    bool pallindrome(string& s){
        int i=0, j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            if(pallindrome(words[i])) return words[i];
            
        }
        return "";
    }
};