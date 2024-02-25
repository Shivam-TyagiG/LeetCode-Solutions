class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int ind = 1;
        for(int i=1; i<nums.size(); i++){
            if(curr != nums[i]){
                nums[ind++] = nums[i];
                curr = nums[i];
            }
        }
        return ind;
    }
};