// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int a[])
    {
        // code here
        int s=0,fl=0;
        for(int i=0;i<n;i++){
	        s+=a[i];
	    }
	    if(s%2!=0)fl=1;
	    int dp[(s/2)+1]={0};
	    dp[0]=1;
	    for(int i=0;i<n;i++){
	        for(int j=(s/2);j>=a[i];j--){
	            if(dp[j]==0){
	                if(dp[j-a[i]]==1)dp[j]=1;
	            }
	        }
	    }
	    if(fl==1||dp[s/2]==0)return 0;
	    else return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends