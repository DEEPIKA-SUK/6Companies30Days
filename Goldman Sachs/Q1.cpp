#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        vector<vector<string> > v;
	    map<string,vector<int>> mp;
	    for(int i=0;i<s.size();i++){
	        string c=s[i];
	        sort(c.begin(),c.end());
	        mp[c].push_back(i);
	    }
	    
	    for(auto it:mp){
	        vector<string> v2;
	        vector<int> v1=it.second;
	        for(auto j:v1)v2.push_back(s[j]);
	        v.push_back(v2);
	    }
	    return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends