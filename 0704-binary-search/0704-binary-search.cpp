class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        //initialise starting and ending 
        int i=0, e=nums.size()-1;
        while(i<=e)
        {
            int mid = i + (e-i)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                e = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return -1;
        
    }
};