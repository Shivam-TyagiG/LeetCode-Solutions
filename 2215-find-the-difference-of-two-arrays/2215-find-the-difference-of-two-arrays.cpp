class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_map<int,int> m2;
        unordered_map<int,int> m1;
        for(int i=0; i<nums1.size(); i++){
            m1[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            m2[nums2[i]]++;
        }
        vector<int> a1;
        for(int i=0; i<nums1.size(); i++){
            if(m2.find(nums1[i])==m2.end()){
                a1.push_back(nums1[i]);
                m2[nums1[i]];
            }
        }
        vector<int> a2;
        for(int i=0; i<nums2.size(); i++){
            if(m1.find(nums2[i])==m1.end()){
                a2.push_back(nums2[i]);\
                m1[nums2[i]];
            }
        }
        vector<vector<int>> ans;
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};