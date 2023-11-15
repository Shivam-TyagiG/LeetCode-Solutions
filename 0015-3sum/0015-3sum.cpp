class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=nums.size()-1;
            int target = -1*nums[i];
            while(j<k){
                int sum = nums[j]+nums[k];
                if(sum == target){
                    vector<int> output;
                    output.push_back(nums[i]);
                    output.push_back(nums[j]);
                    output.push_back(nums[k]);
                    ans.push_back(output);
                    int x=nums[j], y=nums[k];
                    while(j<n && nums[j]==x) j++;
                    while(k>=0 && nums[k]==y) k--;
                }
                else if(sum < target){
                    j++;
                }
                else k--;
            }
        }
        return ans;
    }
};