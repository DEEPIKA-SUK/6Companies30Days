// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string c[], string s){
        // code here
        vector<vector<string>> ans;
        vector<string> h;
        map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[c[i]]++;
        }
        for(auto x:mp)h.push_back(x.first);
        n=h.size();
        int a[n];
        for(int i=0;i<n;i++){
            int j=0;
            while(j<min(s.length(),h[i].length())&&h[i][j]==s[j])j++;
            a[i]=j;
        }
        for(int i=1;i<s.length()+1;i++){
            vector<string> v;
            for(int j=0;j<n;j++){
                if(a[j]>=i)v.push_back(h[j]);
            }
            if(v.size()==0)v.push_back("0");
            sort(v.begin(),v.end());
            ans.push_back(v);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends