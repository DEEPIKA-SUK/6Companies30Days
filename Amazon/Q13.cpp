class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2)q.push({i,j});
            }
        }
        q.push({-1,-1});
        int ans=0;
        while(!q.empty()){
            int fl=0;
            while(q.front().first!=-1 && q.front().second!=-1){
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;
                if(i+1<n && g[i+1][j]==1){
                    g[i+1][j]=2;
                    q.push({i+1,j});
                    if(fl==0){
                        fl=1;
                        ans++;
                    }
                }
                if(j+1<m && g[i][j+1]==1){
                    g[i][j+1]=2;
                    q.push({i,j+1});
                    if(fl==0){
                        fl=1;
                        ans++;
                    }
                }
                if(i-1>=0 && g[i-1][j]==1){
                    g[i-1][j]=2;
                    q.push({i-1,j});
                    if(fl==0){
                        fl=1;
                        ans++;
                    }
                }
                if(j-1>=0 && g[i][j-1]==1){
                    g[i][j-1]=2;
                    q.push({i,j-1});
                    if(fl==0){
                        fl=1;
                        ans++;
                    }
                }
            }
            q.pop();
            if(q.empty())break;
            q.push({-1,-1});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1)return -1;
            }
        }
        return ans;
    }
};