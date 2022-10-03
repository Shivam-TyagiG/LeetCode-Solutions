class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count=1;
        int size=arr.size();
        vector<int> temp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<size-1;i++){
            if(arr[i]==arr[i+1]){
                count=count+1;
            }
            else{
                temp.push_back(count);
                count=1;
            }
            
            if(i==size-2){
                temp.push_back(count);
            }
        }
        size=temp.size();
        sort(temp.begin(),temp.end());
        for(int i=0;i<size-1;i++){
            if(temp[i]==temp[i+1]){
                return false;
            }
        }
        return true;
        
        
    }
};