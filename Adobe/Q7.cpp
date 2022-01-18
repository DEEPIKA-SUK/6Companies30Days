//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dp[1000][1000];
    int func(vector<int>&a,int n,int i){
        if(i>n)return 0;
        if(dp[i][n]!=0)return dp[i][n];
        return dp[i][n]=max(a[i]+min(func(a,n,i+2),func(a,n-1,i+1)),a[n]+min(func(a,n-1,i+1),func(a,n-2,i)));
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    memset(dp,0,sizeof(dp));
        return func(A,n-1,0);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends