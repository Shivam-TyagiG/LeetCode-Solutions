bool cmp(pair<char,int>& a, pair<char, int>& b){
    return a.second<b.second;
}

class Solution {
public:
    string customSortString(string order, string s) {
        int arr[26] = {INT_MAX};
        for(int i=0; i<order.length(); i++){
            arr[order[i]-'a']=i;
        }
        
        vector<pair<char,int>> v;
        for(int i=0; i<s.length(); i++){
            v.push_back({s[i], arr[s[i]-'a']});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        string ans = "";
        for(int i=0; i<v.size(); i++){
            ans+=v[i].first;
        }
        return ans;
        
    }
};