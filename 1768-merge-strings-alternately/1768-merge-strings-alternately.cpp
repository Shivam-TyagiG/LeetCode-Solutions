class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        
        int i=0, j=0; 
        int l1 = word1.length();
        int l2 = word2.length();
        while(i<l1 && j<l2){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        
        while(i<l1) ans+=word1[i++];
        while(j<l2) ans+=word2[j++];
        return ans;
    }
};