class Solution {
public:
    int solve(vector<int>& arr, int target, int low, int high){
        if(low>high) return -1;
        int mid = low+(high-low)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid]>target){
            return solve(arr, target, low, mid-1);
        }
        else
        {
            return solve(arr, target, mid+1, high);
        }
    }
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        return solve(nums, target, low , high);
    }
};