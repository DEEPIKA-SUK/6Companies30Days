#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>g[N];
	    vector<int>vis(N, 0);
	    for(auto x : prerequisites){
	        int u = x.second;
	        int v = x.first;
	        g[u].push_back(v);
	        vis[v]++;
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(vis[i]==0)q.push(i);
	    }
	    int c=0;
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        for(auto v: g[u]){
	            vis[v]--;
	            if(vis[v] == 0)q.push(v);
	        }
	        c++;
	    }
	    return c==N;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends