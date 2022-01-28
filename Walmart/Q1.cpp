class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for(int i=0; i<e.size(); i++) {
            g[e[i][0]].push_back({e[i][1], p[i]});
            g[e[i][1]].push_back({e[i][0], p[i]});   
        }
        vector<int> vis(n, 0);
        priority_queue<pair<double, int>> q;
        q.push({1, start});
        vector<double> ans(n,0);
        ans[start] = 1.0;
        while(!q.empty()) {
            pair<double, int> temp = q.top();
            q.pop();
            double x = temp.first;
            int u = temp.second;
            if(vis[u]==0) {
                vis[u]++;
                for(auto y: g[u]) {
                    if (ans[y.first] < y.second*x) {
                        ans[y.first] = y.second*x;
						q.push({ans[y.first], y.first});
                    }
                }
            }
        }
        return ans[end];
    }
};