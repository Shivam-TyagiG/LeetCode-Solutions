class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]) count1++;
            if(nums[i]<nums[i-1]) count2++;
        }
        if(count1==0 || count2==0) return 1;
        return 0;
        
    }
};