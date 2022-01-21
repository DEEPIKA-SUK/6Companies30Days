class Solution {
public:
    void dfs(vector<int> &vis,vector<int>v[],int u){
        vis[u]=1;
        for(auto x:v[u]){
            if(vis[x]==0)dfs(vis,v,x);
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> v[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(grid[i][j]){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                c++;
                dfs(vis,v,i);
            }
        }
        return c;
    }
};