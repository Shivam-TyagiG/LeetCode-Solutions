class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int num = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>num){
                nums[count]=nums[i];
                num=nums[i];
                count++;
            }
        }
        return count;
    }
};