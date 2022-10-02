class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        char array[n+1];
        int count=0,cont=0;
        strcpy(array,s.c_str());
        for(int i=n-1;i>=0;i--){
            
            if(array[i]!=32){
                count++;
                cont=1;
            }
            if(array[i]==32&&cont){
                
                break;
            }
            
        }
        return count;
    }
};