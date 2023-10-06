class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> ans(n, -1);
        for(int i=0; i<nums1.size(); i++){
            int num = nums1[i];
            for(int j=0; j<nums2.size(); j++){
                
                if(num == nums2[j]){
                    // cout<<j<<" "<<endl;
                    for(int k=j+1; k<nums2.size(); k++){
                        // cout<<num<<" "<<nums2[k]<<" "<<i<<endl;
                        if(nums2[k]>num){
                             ans[i]=nums2[k];
                            // brea = 1;
                            break;
                        }
                    }
                    break;
                }
            }
        }                   
        return ans;
    }
};