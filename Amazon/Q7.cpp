#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    unordered_map<char,int> mp;
		    queue<char> q;
		    string r="";
		    r+=s[0];
		    mp[s[0]]++;
		    q.push(s[0]);
		    for(int i=1;i<s.length();i++){
		        if(mp.find(s[i])==mp.end()){
		            q.push(s[i]);
		            mp[s[i]]++;
		            r+=q.front();
		        }else{
		            mp[s[i]]++;
		                while(!q.empty()&&mp[q.front()]>1)q.pop();
		                if(q.empty())r+='#';
		                else r+=q.front();
		        }
		    }
		    return r;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends