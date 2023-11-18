class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, j=0, n=nums.size()-1;
        int ans = 1;
        while(j<nums.size()){
            if(j < n && nums[j] == nums[j+1]){
                j++;
                continue;
            }
            i=j-1;
            int count = 1, capacity = k;
            while(i>=0 && capacity >= (nums[j]-nums[i])){
                capacity = capacity - (nums[j] - nums[i]);
                count++;
                i--;
            }
            ans = max(ans, count);
            j++;
        }
        return ans;
    }
};