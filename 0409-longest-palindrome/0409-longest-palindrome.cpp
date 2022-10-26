class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char,int> count;
        for(int i=0;i<s.size();i++)
        {
            count[s[i]]++;
        }
        int ans = 0;
        /*
        for(int i=0;i<count.size();i++)
        {
            if(count[s[i]]%2 == 0)
            {
                ans = ans + count[s[i]];
                cout<<count[s[i]]<<endl;
            }
        }
        */
        
        for (auto i = count.rbegin(); i != count.rend(); ++i) 
        {
            
            if(count.size() == 1)
            {
                return i->second;
            }
            
            //cout << i->first<< " = "<< i->second<< endl;
            if((i->second)>=2 )
            {
                ans = ans + (i->second)/2;
            }
        
        }
        if(ans*2 == s.size())
        {
            return ans*2;
        }
        else{
            return ans*2+1;
        }
        
        
    }
};