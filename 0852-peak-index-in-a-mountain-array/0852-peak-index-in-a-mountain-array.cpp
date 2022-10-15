int peakindex(vector<int> arr,int s ,int e)
{
    while(s<e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]<arr[mid+1])        
        {
            
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        if(arr.size()<3)
        {
            return -1;
        }
        int s=1,e=arr.size()-2;
        
        return peakindex(arr,s,e);
    }
};