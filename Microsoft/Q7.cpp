#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends


/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   A[][]: 2D matrix from input
*/

int s=0;
bool ifSafe(int mat[SIZE][SIZE], int x, int y, vector<bool> visited[],int n,int m) {
    return x >= 0 && x < n
        && y >= 0 && y < m
        && mat[x][y] == 1
        && !visited[x][y];
  }
void dfs(int mat[SIZE][SIZE], int x, int y,vector<bool> visited[],int n,int m) {
    visited[x][y] = true;
   
    s++;
    if (ifSafe(mat, x - 1, y - 1, visited,n,m)) {
      dfs(mat, x - 1, y - 1, visited,n,m);
    }
   
    if (ifSafe(mat, x - 1, y, visited,n,m)) {
      dfs(mat, x - 1, y, visited,n,m);
    }
   
    if (ifSafe(mat, x - 1, y + 1, visited,n,m)) {
      dfs(mat, x - 1, y + 1, visited,n,m);
    }
   
    if (ifSafe(mat, x, y - 1, visited,n,m)) {
      dfs(mat, x, y - 1, visited,n,m);
    }
   
    if (ifSafe(mat, x, y + 1, visited,n,m)) {
      dfs(mat, x, y + 1, visited,n,m);
    }
   
    if (ifSafe(mat, x + 1, y - 1, visited,n,m)) {
      dfs(mat, x + 1, y - 1, visited,n,m);
    }
   
    if (ifSafe(mat, x + 1, y, visited,n,m)) {
      dfs(mat, x + 1, y, visited,n,m);
    }
   
    if (ifSafe(mat, x + 1, y + 1, visited,n,m)) {
      dfs(mat, x + 1, y + 1, visited,n,m);
    }
   // return s;
  }
int findMaxArea(int n, int m, int mat[SIZE][SIZE]) {

    // Your code here
   vector<bool> visited[n];
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++) visited[i].push_back(false);
   }

    int count = 0,h;
    s=0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] == 1 && !visited[i][j]) {
          dfs(mat, i, j, visited,n,m);
          count=max(s,count);
          s=0;
        }
      }
    }

    return count;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}  // } Driver Code Ends