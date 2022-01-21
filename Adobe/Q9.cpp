//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string s) { 
        //complete the function here
        int n=s.length();
        if(n==1 || n==2 || n==3)return "-1";
        string ans=s.substr(0,n/2);
        next_permutation(ans.begin(),ans.end());
        if(ans<=s.substr(0,n/2))return "-1";
        string r=ans;
        reverse(r.begin(),r.end());
        if(n&1)ans+=s[n/2];
        ans+=r;
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends