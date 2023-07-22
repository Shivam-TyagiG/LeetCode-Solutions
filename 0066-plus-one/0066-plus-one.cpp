class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n=digits.size();
         for(int i=digits.size()-1; i>=0; i--){
             int sum = digits[i]+1;
             int num = sum%10;
             carry = sum/10;
             digits[i]=num;
             if(carry==0){
                 break;
             }
         }
        if(carry!=0){
            digits.push_back(1);
            rotate(digits.begin(), digits.begin()+n, digits.end());
        }
        return digits;
        
    }
};