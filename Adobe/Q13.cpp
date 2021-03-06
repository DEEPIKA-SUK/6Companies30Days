#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        vector<int> v;
        unordered_set<int> s;
        for(int i = 0; i < M ;i++){
            s.insert(B[i]);
        }
        for(int i=0;i<N;i++){
            if(s.find(A[i])!=s.end()){
                int temp =lower_bound(v.begin(),v.end(),A[i])-v.begin();
                if(temp==v.size()){
                    v.push_back(A[i]);
                }else{
                    v[temp]= A[i];
                }
            }
        }
        return N+M-2*v.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends