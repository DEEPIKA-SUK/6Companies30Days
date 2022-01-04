#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    vector<ull> v(n);
	    v[0]=1;
	    int i=0,j=0,k=0,h=1;
	    for(int t=0;t<n-1;t++){
	        ull x=min(v[i]*2,min(v[j]*3,v[k]*5));
	        v[h++]=x;
	        if(x==v[i]*2)i++;
	        if(x==v[j]*3)j++;
	        if(x==v[k]*5)k++;
	    }
	    return v[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends