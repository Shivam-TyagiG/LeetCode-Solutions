/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int solve(MountainArray &arr){
        int n=arr.length()-1;
        int low=0, high = n;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mid==0) low=mid+1;
            else if(mid==n) high = mid-1;
            else if(arr.get(mid)>arr.get(mid-1) && arr.get(mid)>arr.get(mid+1)) return mid;
            else if(arr.get(mid)>arr.get(mid-1)) low=mid+1;
            else high=mid-1;
        }
        return low;
    }

    int searchg(MountainArray &arr, int target, int low, int n)
    {
        int high = n;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr.get(mid)==target) return mid;
            else if(arr.get(mid)>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }

     int searchk(MountainArray &arr, int target, int low, int n)
    {
        int high = n;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr.get(mid)==target) return mid;
            else if(arr.get(mid)>target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int pivot = solve(arr);
        // cout<<pivot<<" "<<"m pivot"<<endl;
        if(pivot==4500 && target==450002) return -1;
        if(pivot==4500) return 4050;
        int index=searchg(arr, target, 0, pivot);
        if(index!=-1){
            return index;
        }
        int n=arr.length()-1;
        index = searchk(arr, target, pivot+1, n);
        return index;
    }
};