//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) {
        // code here
        if(n<=2)return n;
        vector<unordered_map<int,int>> dp(n);
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=a[j]-a[i];
                if(dp[i].find(d)!=dp[i].end()){
                    dp[j][d]=dp[i][d]+1;
                }else dp[j][d]=2;
                mx=max(mx,dp[j][d]);
            }
        }
        return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends