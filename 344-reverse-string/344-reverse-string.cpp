class Solution {
public:
    void reverseString(vector<char>& s) {
        /*
        int a=0;
        int e=s.size()-1;
        while(a<e){
            swap(s[a++],s[e--]);
        }
        */
        reverse(s.begin(),s.end());
    }
};