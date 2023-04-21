struct VectorHasher {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
class Solution {
public:
    void solve(vector<int> nums,vector<vector<int>> &ans,int index,vector<int> output){
        
        //Base condition
        if(index==nums.size()){
            ans.push_back(output);
             
            return ;
        }
        
        //processing
        
        //exclude
        solve(nums,ans,index+1,output);
        
        //include
        output.push_back(nums[index]);
        solve(nums,ans,index+1,output);
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<vector<int>>::iterator ip;
        int index=0;
        vector<int> output;
        solve(nums,ans,index,output);
        sort(ans.begin(), ans.end());
        unordered_map<vector<int>, bool, VectorHasher> m;
        vector<vector<int>> ret;
        for(auto i:ans){
            if(!m[i]){
                m[i]=true;
                ret.push_back(i);
            }
        }
        return ret;
    }
};