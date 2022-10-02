class Solution {
public:
    string removeDuplicates(string s) {
        for(int i=0;i<s.size()-1;i++)
        {
            
            if(s[i]==s[i+1]){
                s.erase(i,2);
                if(s.size()<2){
                    break;
                }
                if(i-2>=0){
                    i=i-2;
                }
                else{
                    i=-1;
                }
                continue;
            }
           
        }
        return s;
        
    }
};