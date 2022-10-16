int solve(vector<int> nums)
{
    int s=0,e=nums.size()-1;
    while(s<e)
    {
        int mid = s + (e-s)/2;
        if(nums[mid]>=nums[0])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}

int binarysearch(vector<int> nums,int s,int e,int target)
{
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        
        if(nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target ){
            e=mid-1;
            
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //Find pivot 
        int pivindex = solve(nums);
        cout<<pivindex;
        if(nums[pivindex] == target)
        {
            return pivindex;
        }
        
        if(target <= nums[nums.size()-1] && target >= nums[pivindex])
        {
            int e=nums.size() - 1;
            return binarysearch(nums,pivindex,e,target);
        }
        else{
            int s=0;
            return binarysearch(nums,s,pivindex-1,target);
        }
       
        
    }
};