#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> a, int k) {
        // Code here
        if(a.size()%2)return 0;
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++)mp[a[i]%k]++;
        bool fl= (mp[0]%2==0 );
        if(k%2==0)fl&=(mp[k/2]%2==0);
        if(fl==0)return 0;
        for(int i=1;i<k;i++){
            if(mp[i]!=mp[k-i])return 0;
        }
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends