class Solution {
public:
    bool check(vector<int>& arr) {int count = 0;
                                  int i=0;
        for( i=1; i<arr.size(); i++){
            if(arr[i]<arr[i-1]) count++;
        }
                                  
        if(arr[i-1]>arr[0]) count++;
                                   if(count<=1) return 1;
                                   else return 0;
    }
};