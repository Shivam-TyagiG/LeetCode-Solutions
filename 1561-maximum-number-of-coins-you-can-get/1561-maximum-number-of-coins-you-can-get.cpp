class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size(), M=0;
        int freq[10001]={0};
        #pragma unroll
        for(int x: piles){
            freq[x]++;
            M=max(M, x);
        }
    //    cout<<M<<endl;
        int ans=0, count=0, k=n/3*2;
        bool alice=0;
        #pragma unroll
        for(int x=M; count<n/3; x--){
            if (freq[x]>0){
                int f=freq[x]+alice;
                int f0=f>>1;
                f0=(f0+count>n/3)?n/3-count:f0;
                count+=f0;
                ans+=f0*x;
                alice=(f&1)?1:0;
            }
            
        }
        return ans;
    }
}
;auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();