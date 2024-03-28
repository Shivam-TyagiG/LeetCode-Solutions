class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> freq;
        int maxi = 0;
        int i=0, j=0;
        while(j<nums.size()){
            freq[nums[j]]++;
            while( freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
        
        
    }
};