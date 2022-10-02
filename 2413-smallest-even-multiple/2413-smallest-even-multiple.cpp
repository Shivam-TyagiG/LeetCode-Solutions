class Solution {
public:
    int smallestEvenMultiple(int n) {
        int k=n;
        while (n%2==0&&n*2>k){
            n=n/2;
        
        
        }
        return 2*n;
    }
};