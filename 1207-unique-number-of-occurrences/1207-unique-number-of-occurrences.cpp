class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

         int size=arr.size();

        unordered_map<int,int> freq;
        for(int i=0; i<size; i++)
        {
            freq[arr[i]]++;
        }
        
        unordered_set<int> unique;
        for(auto i : freq)
        {
            if(unique.count(i.second))
                return false;
            else
                unique.insert(i.second);
        }
        return true;
    }
};