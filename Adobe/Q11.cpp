#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string r="";
        if(s[0]-'A'>=0&&s[0]-'A'<26)r+=s[0]-'A'+'a';
        else r+=s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]-'A'>=0&&s[i]-'A'<26){
                r+=' ';
                r+=s[i]-'A'+'a';
            }else r+=s[i];
        }
        return r;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends