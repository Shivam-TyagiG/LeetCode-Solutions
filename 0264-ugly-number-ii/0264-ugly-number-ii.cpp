class Solution {
public:
    int nthUglyNumber(int n) {
        
        int arr[n];
        arr[0]=1;
        int p1=0, p2=0, p3=0;
        for(int i=1; i<n;i++){
            int val = min(arr[p1]*2, min(arr[p2]*3, arr[p3]*5));
            arr[i]=val;
            if(arr[p1]*2==val) p1++;
            if(arr[p2]*3==val) p2++;
            if(arr[p3]*5==val) p3++;
            
        }
        return arr[n-1];
    }
};