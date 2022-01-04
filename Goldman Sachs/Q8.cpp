#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    int mod=1000000007;
		int CountWays(string s){
		    if (s[0] == '0') return 0;
            if (s.size() == 1) return 1;
            int len = s.size(), dp[3];
            dp[0] = 1;
            dp[1] = (s[0] == '1' || s[0] == '2' && s[1] < '7' ? 1 : 0) + (s[1] != '0');
            for (int i = 2, curr, prev; i < len; i++) {
                curr = i % 3;
                prev = curr ? curr - 1 : 2;
                if (s[i] == '0' && (s[i - 1] > '2' || s[i - 1] == '0')) return 0;
                dp[curr] = s[i] != '0' ? dp[prev] : 0;
                if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') dp[curr] =( dp[curr]+ dp[prev ? prev - 1 : 2])%mod;
            }
            return dp[(len - 1) % 3];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends