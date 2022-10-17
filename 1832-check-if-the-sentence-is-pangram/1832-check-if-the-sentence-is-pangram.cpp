class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        set<char> arr;
        for(int i=0 ; i<sentence.length() ; i++)
        {
            arr.insert(sentence[i]);
        }
        if(arr.size()==26)
        {
            return true;
        }
        return false ;
        
    }
};