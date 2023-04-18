class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i])!=m.end()) continue;
            
            int ls = 0, rs=0;
            if(m.find(nums[i]-1)!=m.end()) ls=m[nums[i]-1];
            if(m.find(nums[i]+1)!=m.end()) rs = m[nums[i]+1];
            
            int total = 1+ls+rs;
            ans = max(ans, total);
            m[nums[i]]=total;
            m[nums[i]-ls]=total;
            m[nums[i]+rs]=total;
        }
        
        return ans;
    }
};