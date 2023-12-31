class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        unordered_map<char, int> m;
        for(int i=0; i<s.length(); i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = i;
            }
            else{
                ans = max(ans, i-m[s[i]]-1);
            }
        }
        return ans;
    }
};