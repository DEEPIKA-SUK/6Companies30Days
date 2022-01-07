// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> board){
        // code here
        map<string,int> mp;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(board[i][j]!=0){
                string a="r"+to_string(i)+to_string(board[i][j]);
                string b="c"+to_string(j)+to_string(board[i][j]);
                int box=(i/3)*3+j/3;
                string c="box"+to_string(box)+to_string(board[i][j]);
                if(mp.find(a)!=mp.end())return false;
                else mp[a]++;
                if(mp.find(b)!=mp.end())return false;
                else mp[b]++;
                if(mp.find(c)!=mp.end())return false;
                else mp[c]++;
               }
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends