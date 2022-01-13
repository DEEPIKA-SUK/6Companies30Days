#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int k) {
        // Your code goes here
        vector<vector<int> > ans;
        map<vector<int>,int> mp;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size()-3;i++){
            for(int j=i+1;j<a.size()-2;j++){
                int l=j+1,r=a.size()-1,s=k-a[i]-a[j];
                while(l<r){
                    if(a[l]+a[r]==s){
                        vector<int> v(4);
                        v[0]=a[i];
                        v[1]=a[j];
                        v[2]=a[l];
                        v[3]=a[r];
                        if(mp.find(v)==mp.end()){
                            ans.push_back(v);
                            mp[v]++;
                        }
                        l++;
                        r--;
                    }else if(a[l]+a[r]>s)r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends