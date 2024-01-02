class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        bool flag = true;
        while(flag && nums.size()>0){
            flag=false;
            map<int,int> vis;
            vector<int> num;
            for(int i=0; i<nums.size(); i++){
                num.push_back(nums[i]);
            }
            nums.clear();
            for(int i=0; i<num.size(); i++){
                if(vis.find(num[i])==vis.end()){
                    output.push_back(num[i]);
                    vis[nums[i]]=i;
                }
                else{
                    flag=true;
                    nums.push_back(num[i]);
                }
            }
            
            ans.push_back(output);
            output.clear();
        }
        return ans;
    }
};