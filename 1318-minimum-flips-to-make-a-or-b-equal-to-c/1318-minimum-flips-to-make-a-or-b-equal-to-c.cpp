class Solution {
public:
    int minFlips(int a, int b, int c) {
        string sa = "";
        string sb = "";
        string sc = "";
        while(a!=0){
            int digit = a&1;
            a=a>>1;
            sa = to_string(digit)+sa;
        }
        while(b!=0){
            int digit = b&1;
            b=b>>1;
            sb = to_string(digit)+sb;
        }
        while(c!=0){
            int digit = c&1;
            c=c>>1;
            sc = to_string(digit)+sc;
        }
        int alength = sa.length();
        int blength = sb.length();
        int clength = sc.length();
        int maxlength = max(alength, max(blength, clength));
        for(int i=alength; i<maxlength; i++){
            sa="0"+sa;
        }
        for(int i=blength; i<maxlength; i++){
            sb="0"+sb;
        }
        for(int i=clength; i<maxlength; i++){
            sc="0"+sc;
        }
        // cout<<maxlength<<endl;
        int count=0;
        for(int i=0; i<maxlength; i++){
            // cout<<sa[i]<<" "<<sb[i]<<" "<<sc[i]<<endl;
            if(sc[i]=='1'){
                if(sa[i]=='0' && sb[i]=='0'){
                    count++;
                    // cout<<i<<endl;
                }
                
            }
            else{
                if(sa[i]=='1' && sb[i]=='1') count+=2;
                else if(sa[i]=='1' || sb[i]=='1') {
                    count++;
                }
            }
        }
        
        return count;
        
    }
};