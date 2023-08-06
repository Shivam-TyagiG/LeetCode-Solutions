//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert_at_bottom(stack<int>& s, int data){
        if(s.empty()){
            s.push(data);
            return ;
        }
        int d = s.top();
        s.pop();
        insert_at_bottom(s, data);
        s.push(d);
    }
    void Reverse(stack<int> &St){
        if(St.empty()) return ;
        int top = St.top();
        St.pop();
        Reverse(St);
        insert_at_bottom(St, top);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends