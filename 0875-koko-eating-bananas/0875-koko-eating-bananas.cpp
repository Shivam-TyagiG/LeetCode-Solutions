class Solution {
private:
    long long checkhours(vector<int>& piles, int mid){
        long long cnt = 0;
        for(int i=0;i<piles.size();i++){
            cnt += ceil(piles[i]/(double)mid);
        }
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {  
        int s = 1; 
        //Max speed to eat
        int e = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(s <= e){
            int mid = s+(e-s)/2;
            //Total time taken to eat bananas
            long long totalTime = checkhours(piles,mid);
            //Since we have to find minimum speed , we need to keep checking for lowest possible speed
            if(totalTime <= h){
                ans = mid; e = mid-1; 
            }
            else  s = mid+1;
        }
        return ans;
    }
};