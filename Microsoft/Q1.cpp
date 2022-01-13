#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)sum+=arr[i];
	    sort(arr,arr+n);
	    int s=sum/2;
	    int dp[s+ 1]={0};
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=s;j>=arr[i];j--){
              if (dp[j-arr[i]]==1)dp[j] = 1;
            }
        }
	    for(int i=s;i>=0;i--){
	        if(dp[i])return abs(sum-2*i);
	    }
	    return 0;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends