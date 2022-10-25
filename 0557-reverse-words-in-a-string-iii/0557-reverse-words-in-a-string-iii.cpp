class Solution {
public:
    string reverseWords(string s) {
        
        int m=0;
        for(int i=0;i<s.size();i++ )
        {
            int n=i-1;
            if((s[i] == ' ' && s[i+1] != ' ') || (i==s.size()-1))
            {
                if(i==s.size()-1)
                {
                    n=i;
                }
                while(m<n)
                {
                    swap(s[m],s[n]);
                    m++;
                    n--;
                }
                m=i+1;
                
            }
        }
        return s;
    }
};