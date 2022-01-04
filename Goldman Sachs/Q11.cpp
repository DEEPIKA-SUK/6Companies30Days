#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *A, int n) {
        // code here
        long long int sqts=((long long int)n*(n+1)*(2*n+1))/6,ts=((long long int)n*(n+1))/2,s=0,ss=0;
        for(int i=0;i<n;i++){
            ss+=(long long int)A[i]*(long long int)A[i];
            s+=(long long int)A[i];
        }
        long long int x,y;
        int *v=new int[2];
        x=ts-s;
        y=(sqts-ss)/x;
        v[0]=(y-x)/2;
        v[1]=(y+x)/2;
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends