class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> q1;
        vector<int> q2;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >=0) q1.push_back(nums[i]);
            else q2.push_back(nums[i]);
        }
        int count = 0;
        int i=0, j=0;
        int k=0;
        while(count < nums.size()){
            nums[k++] = q1[i++];
            nums[k++] = q2[j++];
            count+=2;
        }
        return nums;
    }
};