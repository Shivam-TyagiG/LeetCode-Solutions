class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> fs(26,0);
        vector<int> fp(26, 0);
        
        int ls = s.length();
        int lp = p.length();
        
        vector<int> ans;
        if(ls<lp) return ans;
        int i=0;
        while(i<lp){
            fs[s[i]-'a']++;
            fp[p[i]-'a']++;
            i++;
        }
        i--;
        
        int j=0;
        while(i<ls){
            if(fs==fp) ans.push_back(j);
            i++;
            if(i<ls) fs[s[i]-'a']++;
            fs[s[j]-'a']--;
            j++;
            
        }
        return ans;
        
    }
};