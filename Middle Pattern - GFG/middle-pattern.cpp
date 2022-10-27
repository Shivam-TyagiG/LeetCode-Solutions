//{ Driver Code Starts
#include <iostream>
using namespace std;

void printPattern(string s);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	printPattern(s);
	cout<<endl;
	
}
	
	return 0;
}
// } Driver Code Ends


/*method prints the given pattern in a single line */
void printPattern(string s)
{
    int l = s.length();
    int si = l/2;
    for(int i = si ; i<l ; i++)
    {
        for(int j=si ; j<=i ; j++)
        {
            cout<<s[j];
        }
        cout<<"$ ";
    }
    string ans  = "";
    for(int i=si;i<l;i++)
    {
        ans=ans+s[i];
    }
    for(int i=0;i<si;i++){
        cout<<ans;
        for(int j=0;j<=i;j++)
        {
            cout<<s[j];
        }
        cout<<"$ ";
    }
   //Your code here
}
