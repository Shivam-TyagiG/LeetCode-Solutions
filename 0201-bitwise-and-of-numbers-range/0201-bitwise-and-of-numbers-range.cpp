class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long mask = (1l<<31);
        long ans = 0;
        while(mask){
            if((mask & m )==(mask&n)){
                if(mask&m) ans+=mask;
                mask>>=1;
            }
            else{
                break;
            }
        }
        return ans;
    }
};