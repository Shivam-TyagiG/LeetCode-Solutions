class Solution {
public:
    string sortVowels(string s) {
        int j=s.length();
        string t="";
        for(int i=0; i<j; i++){
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                t+=s[i];
            }
            
        }
        int k=0;
        sort(t.begin(), t.end());
         for(int i=0; i<j; i++){
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i]=t[k];
                k++;
            }
            
        }
        return s;
        
    }
};