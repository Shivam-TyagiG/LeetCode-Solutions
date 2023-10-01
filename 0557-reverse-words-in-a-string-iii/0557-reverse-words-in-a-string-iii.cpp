class Solution {
public:
    void reverse(int i, int j, string& s){
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
    string reverseWords(string s) {
        int lastpos = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                reverse(lastpos, i-1, s);
                lastpos=i+1;
            }
        }
        reverse(lastpos, s.length()-1, s);
        return s;
    }
};