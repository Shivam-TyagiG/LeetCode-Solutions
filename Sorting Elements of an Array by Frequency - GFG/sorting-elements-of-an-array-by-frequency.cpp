#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct triplet{
    int freq;
    int  num;
    int index;
};

bool cmp(triplet& a, triplet& b){
    if(a.freq!=b.freq){
        if(a.freq>b.freq) return 1;
        if(a.freq<b.freq) return 0;
    }
    else{
        if(a.num<b.num) return 1;
        else return 0;
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    vector<int> frequency(66);
	    for(int i=0; i<n; i++){
	        frequency[arr[i]]++;
	    }
	    vector<triplet> m;
	    for(int i=0; i<n; i++){
	        triplet t;
	        t.freq = frequency[arr[i]];
	        t.num = arr[i];
	        t.index = i;
	        m.push_back(t);
	    }
	    sort(m.begin(), m.end(), cmp);
	    for(auto i:m){
	        cout<<i.num<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}