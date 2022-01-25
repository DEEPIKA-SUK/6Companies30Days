class Solution {
public:
    Node* f(vector<vector<int>>& grid,int x,int y,int g,int h,int u){
        int sum=0;
        for(int i=x;i<y;i++){
            for(int j=g;j<h;j++){
                sum+=grid[i][j];
            }
        }
        Node* ans;
        if(sum==0)ans=new Node(false,true);
        else if(sum==(u*u))ans=new Node(true,true);
        else{
            ans=new Node(false,false);
            u=u/2;
            ans->topLeft = f(grid,x,x+u,g,g+u,u);
            ans->topRight = f(grid,x,x+u,g+u,h,u);
            ans->bottomLeft = f(grid,x+u,y,g,g+u,u);
            ans->bottomRight = f(grid,x+u,y,g+u,h,u);
        }
        return ans;
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        Node* ans = f(grid,0,n,0,n,n);
        return ans;
    }
};