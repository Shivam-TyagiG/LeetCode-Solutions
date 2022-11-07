class Solution {
    private:
    void merge(vector<int> &arr,int s,int e)
    {
        int mid  = s+(e-s)/2;
        int len1 = mid-s+1;
        int len2 = e-mid;
        int* first = new int[len1];
        int* second=  new int[len2];
        
        //copy the elemet;
        int k=s;
        for(int i=0;i<len1;i++)
        {
            first[i]=arr[k++];
        }
        k=mid+1;
        for(int i=0;i<len2;i++)
        {
            second[i]=arr[k++];
        }
        
        //merge 2 sorted array
        int index1 = 0;
        int index2 = 0;
        int mainarrayindex = s;
        while(index1<len1 && index2<len2)
        {
            if(first[index1] < second[index2])
            {
                arr[mainarrayindex++] = first[index1++];
            }
            else{
                arr[mainarrayindex++] = second[index2++];
            }
        }
        
        //copy the remaining element
        while(index1<len1)
        {
            arr[mainarrayindex++]=first[index1++];
        }
        while(index2<len2)
        {
            arr[mainarrayindex++]  = second[index2++];
        }
    }
    private:
    void MergeSort(vector<int> & nums,int s,int e)
    {
        if(s>=e)
        {
            return ;
        }
        int mid  =  s+(e-s)/2;
        MergeSort(nums,s,mid);
        MergeSort(nums,mid+1,e);
        merge(nums,s,e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int s= 0 ;
        int e = nums.size()-1;
        MergeSort(nums,s,e);
        return nums;
    }
};