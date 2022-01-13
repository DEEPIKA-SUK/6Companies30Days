#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        vector<int> v;
        int m=r,n=c;
        int k=0,l=0,last_row=m-1,last_col=n-1;
        while(k<=last_row && l<=last_col){
            for(int i=l;i<=last_col;i++)v.push_back(mat[k][i]);
            k++;
            for(int i=k;i<=last_row;i++)v.push_back(mat[i][last_col]);
            last_col--;
            if(k<=last_row){
                for(int i=last_col;i>=l;i--)v.push_back(mat[last_row][i]);
                last_row--;
            }
            if(l<=last_col){
                for(int i=last_row;i>=k;i--)v.push_back(mat[i][l]);
                l++;
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends