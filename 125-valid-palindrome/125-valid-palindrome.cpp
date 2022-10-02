class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
    int e=s.length();
    int a=0;
    while(a<e){
        if((s[a]<97||s[a]>122)&&(s[a]>57||s[a]<48)){
            a++;
        }
        else if((s[e]<97||s[e]>122)&&(s[e]>57||s[e]<48)){
            e--;
        }
        else{
            if(s[a]==s[e]){
                a++;
                e--;
            }
            else{
                return 0;
            }
        }
     
        
    }
    
    return 1;
    }
};