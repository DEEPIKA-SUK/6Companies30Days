class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1)break;
                c++;
            }
            v.push_back(c);
        }
        int p=0,ans=0;
        while(p<n){
            int d=n-1-p;
            if(v[p]<d){
                int j=-1;
                for(int i=p+1;i<n;i++){
                    if(v[i]>=d){
                        j=i;
                        break;
                    }
                }
                if(j==-1)return j;
                ans+=j-p;
                int t=v[j];
                for(int i=j;i>p;i--)v[i]=v[i-1];
                v[p]=t;
            }
            p++;
        }
        return ans;
    }
};