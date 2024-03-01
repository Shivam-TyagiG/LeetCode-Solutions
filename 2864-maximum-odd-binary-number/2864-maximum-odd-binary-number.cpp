class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '1') count++;
        }
        count--;
        int i=0;
        while(count--){
            s[i] = '1';
            i++;
        }
        for( ; i<n; i++){
            s[i] = '0';
        }
        s[n-1] = '1';
    
        
        return s;
    }
};