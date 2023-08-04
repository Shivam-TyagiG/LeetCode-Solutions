class Solution {
public:
    void conquer(vector<int>& nums, int i, int mid, int j){
        int first = i, second = mid+1;
        vector<int> arr;
        while(first<=mid && second<=j){
            if(nums[first]<=nums[second]){
                arr.push_back(nums[first]);
                first++;
            }
            else{
                arr.push_back(nums[second]);
                second++;
            }
        }
        
        while(first<=mid){
            arr.push_back(nums[first]);
            first++;
        }
        while(second<=j){
            arr.push_back(nums[second]);
            second++;
        }
        
        for(int k=i; k<=j; k++){
            nums[k]=arr[k-i];
        }
    }
    void divide(vector<int>& nums, int i, int j){
        if(i>=j) return ;
        int mid = i+(j-i)/2;
        divide(nums, i, mid);
        divide(nums, mid+1, j);
        conquer(nums, i, mid, j);
    }
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size()-1);
        return nums;
    }
};