class Solution {
public:

    int longestStrChain(vector<string>& words) {
        // Sort the words by their lengths
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        // Map to store the longest chain length for each word
        unordered_map<string, int> longestChainLength;

        // Initialize the answer
        int maxChainLength = -1;

        for(auto &word: words){
            // Initialize the chain length for the current word
            longestChainLength[word] = 1;

            // Try removing one character at a time from the word and check if the resulting word exists
            for(int i = 0 ; i < word.size() ; i++){
                string reducedWord = word.substr(0, i) + word.substr(i + 1) ;

                // If the reduced word exists in the map
                if(longestChainLength.find(reducedWord) != longestChainLength.end())
                    // Update the chain length for the current word
                    longestChainLength[word] = max(longestChainLength[word], longestChainLength[reducedWord] + 1) ;
            }

            // Update the maximum chain length seen so far
            maxChainLength = max(maxChainLength, longestChainLength[word]) ;
        }

        return maxChainLength;
    }
};