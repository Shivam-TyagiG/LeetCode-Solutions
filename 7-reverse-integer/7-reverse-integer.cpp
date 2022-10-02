class Solution {
public:
    int reverse(long int x) {
        long int s=0;
        long int neg=1;
        while (x!=0)
        {
            
            int p=x%10;
            if((s>INT_MAX/10)||(s<INT_MIN/10)){
                return 0;
            }
            s=s*10+p;
            x=x/10;
        }
        return s*neg;
        
        
    }
};