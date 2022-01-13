#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int f;
	void dfs(vector<int> adj[],vector<int> &vis,int u, int c, int d){
	    vis[u]++;
	    for(auto x:adj[u]){
	        if(vis[x]==0){
	            if(f&&x==c&&u==d)continue;
                if(f&&x==d&&u==c)continue;
	            dfs(adj,vis,x,c,d);
	        }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        int fl=0;
        f=0;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(adj,vis,i,c,d);
                fl++;
            }
        }
        int fl1=0;
        f=1;
        vector<int> vis1(V,0);
        for(int i=0;i<V;i++){
            if(vis1[i]==0){
                dfs(adj,vis1,i,c,d);
                fl1++;
            }
        }
        if(fl!=fl1)return 1;
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends