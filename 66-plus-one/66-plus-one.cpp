class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        for(int i=digits.size()-1;i>=0;i--){
            int sum=digits[i]+1;
            //cout<<sum<<" ";
            digits[i]=sum%10;
            //cout<<digits[i]<<" ";
            carry=sum/10;
            if (carry==0){
                break;
            }
            
        }
        if(carry==1){
                digits.push_back(1);
                rotate(digits.rbegin(),digits.rbegin()+1,digits.rend());
                //digits.insert(digits.begin(),1);
            }
        return digits;
        
        
        
    }
};