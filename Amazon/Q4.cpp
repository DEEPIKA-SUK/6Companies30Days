// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int bk[28][28];
    string ans;
    void func(int i,int j){
        if(i==j){
          ans+=char(i+'A'-1);
          return;
        }
        ans+="(";
        func(i,bk[i][j]);
        func(bk[i][j]+1,j);
        ans+=")";
    }

    string matrixChainOrder(int arr[], int n){
        // code here
        ans="";
        int dp[28][28],sum,j;
	    memset(dp,0,sizeof(dp[0][0])*28*28);
	    for(int p=2;p<n;p++){
	        for(int i=1;i<n-p+1;i++){
	            int mn=INT_MAX-1;
	            j=i+p-1;
	            for(int k=i;k<j;k++){
	                sum=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
	                if(mn>sum){
	                    mn=sum;
	                    bk[i][j]=k;
	                }
	            }
	            dp[i][j]=mn;
	        }
	    }
	    func(1,n-1);
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
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends