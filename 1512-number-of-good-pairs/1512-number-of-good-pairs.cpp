class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        int i=1;
        int count = 1;
        while(i<n){
            if(nums[i]==nums[i-1]){
                ans+=count;
                count++;
            }else{
                count=1;
            }
            i++;
        }
        return ans;
    }
};