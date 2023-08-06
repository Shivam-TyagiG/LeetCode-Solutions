//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sort_push(stack<int>& s, int d){
    if(s.empty() || s.top()<=d){
        s.push(d);
        return ;
    }
    
    int da = s.top();
    s.pop();
    sort_push(s, d);
    s.push(da);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty()){
       return ;
   }
   int d = s.top();
   s.pop();
   sort();
   sort_push(s, d);
}