// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    int numOfWays(int n, int x)
    {
        // code here
        long long dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = dp[1] = 1;
        int mx = pow(n,1.0/x);
        for(int i=2;i<= mx;i++){
            int h = pow(i,x);
            for(int j=n;j>=h;j--){
                dp[j] =(dp[j]+ dp[j-h])%1000000007;
            }
        }
        
        return dp[n]%1000000007;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends