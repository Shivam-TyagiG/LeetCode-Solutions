class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq1;
        map<int, int> freq2;
        for(int i=0; i<nums1.size(); i++) freq1[nums1[i]]++;
        for(int i=0; i<nums2.size(); i++) freq2[nums2[i]]++;
        vector<int> ans;
        for(auto i:freq1){
            int ele = i.first;
            int count1 = i.second;
            int count2 = freq2[ele];
            int freq =  min(count1, count2);
            while(freq>0){
                    freq--;
                    ans.push_back(ele);
                }
        }
        return ans;
    }
};