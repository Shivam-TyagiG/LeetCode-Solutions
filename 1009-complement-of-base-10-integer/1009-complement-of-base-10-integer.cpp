class Solution {
public:
    int bitwiseComplement(int n) {
        int mask=0;
        int q=n;
        if (n==0){
            return 1;
        }
        while(q!=0){
            q=q>>1;
            mask=(mask<<1)|1;
        }
        return (~n) & mask;
    }
};