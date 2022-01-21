#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dfs(vector<vector<char>>& a,int i,int j,string word,int idx,int n,int m){
        if(idx==word.length()-1)return true;
        a[i][j]-=65;
        if(i+1<n && a[i+1][j]==word[idx+1] && dfs(a,i+1,j,word,idx+1,n,m)){
            return 1;
        }
        if(i-1>=0 &&a[i-1][j]==word[idx+1] && dfs(a,i-1,j,word,idx+1,n,m)){
            return 1;
        }
        if(j+1<m && a[i][j+1]==word[idx+1] && dfs(a,i,j+1,word,idx+1,n,m)){
            return 1;
        }
        if(j-1>=0&&a[i][j-1]==word[idx+1] && dfs(a,i,j-1,word,idx+1,n,m)){
            return 1;
        }
        a[i][j]+=65;
        return 0;
    }
    bool isWordExist(vector<vector<char>>& a, string s) {
        // Code here
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==s[0] && dfs(a,i,j,s,0,n,m))return 1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends