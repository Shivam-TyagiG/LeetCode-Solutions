class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,bool> ans;
        for(int i=0 ; i<nums.size() ; i++)
        {
            int ele = nums[i];
            if(ans[ele] != true){
                
                ans[nums[i]]=true;
            }
            else{
                return true;
            }
        }
        
        return false;
        
        
    }
};