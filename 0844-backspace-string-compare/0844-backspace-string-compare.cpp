class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> s1;
        stack<char> s2;
        int l=s.length();
        int i=0;
        while(i<l){
            if(s[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(s[i]);
            }
            i++;
        }
        
        i=0;
        l=t.length();
        while(i<l){
            if(t[i]=='#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                    s2.push(t[i]);
                }
            i++;
        }
        
        int l1 = s1.size();
        int l2 = s2.size();
        if(l1!=l2) return 0;
        
        while(!s1.empty()){
            char a = s1.top();
            s1.pop();
            char b = s2.top();
            s2.pop();
            if(a!=b) return 0;
        }
        return 1;
    }
};