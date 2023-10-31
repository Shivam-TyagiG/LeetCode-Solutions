class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        int prev = pref[0];
        int curr = pref[0];
        for(int i=1; i<n; i++){
            curr = pref[i];
            pref[i] = pref[i]^prev;
            prev = curr;
        }
        return pref;
    }
};