class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0||q.size()==n*n) return -1;
        int d1[]={-1,1,0,0};
        int d2[]={0,0,-1,1};
        int ans=0;
        while(!q.empty()){
            int t=q.size(); 
            while(t--){
                pair<int,int> p=q.front();
                int x=p.first,y=p.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int h=x+d1[i],g=y+d2[i];
                    if(h>=0&&h<n&&g>=0&&g<n&&grid[h][g]==0){
                        grid[h][g]=1;
                        q.push({h,g});                    
                    }
                }
           }      
           ans++;
        }
        return ans-1;
    }
};