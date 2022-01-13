#include<bits/stdc++.h>
using namespace std;
#define ll long long


 // } Driver Code Ends


// Function to print all binary numbers upto n

vector<string> generate(long long N)
{
	// Your code here
	vector<string> v;
	queue<string> q;
	q.push("1");
	long long i=1;
	while(i<=N){
	    string s=q.front();
	    v.push_back(s);
	    q.pop();
	    q.push(s+"0");
	    q.push(s+"1");
	    i++;
	}
	return v;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends