class Solution {
public:
    int func(vector<int> &vis,int i,stack<int>&st,vector<int> g[]){
        vis[i]=1;
        for(auto x:g[i]){
            if(vis[x]==1)return 1;
            if(vis[x]==0)if(func(vis,x,st,g))return 1;
        }
        st.push(i);
        vis[i]=2;
        return 0;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> g[n];
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            int fl=0;
            g[p[i][1]].push_back(p[i][0]);
        }
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(func(vis,i,st,g))return ans;
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};