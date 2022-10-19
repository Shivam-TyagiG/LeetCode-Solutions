class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int last_element_at=0;
        int last_index_s=s.length()-1;
        int starting_index_s=0;
        
        
        //loop for s string 
        while(starting_index_s<=last_index_s){
            
            
            //initialise k to check the elemt in string found or not
            int k=last_element_at;
            
            //loop for t string to check the element of s pesent in it or not
            for(int i=last_element_at;i<t.length();i++){
                
                
                if(s[starting_index_s]==t[i]){
                    
                    //point the next index 
                    last_element_at=i+1;
                    break;
                }
                
            }
            
            //check element is found or not if found then last_element index is change if not found then it same so we return false if not found 
            if(k==last_element_at){
                return 0;
            }
            
            
            //now point the counter to next element 
            starting_index_s++;
            
        }
        
        
        //return true bcz loop is complete it means all item are found after 1 another
        return true;
    }
};