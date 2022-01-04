#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  string r="";
  for(int i=0;i<s.length();i++){
      int j=i+1;
      while(j<s.length()&&s[j]==s[i])j++;
      char c=j-i+'0';
      r+=s[i];
      r+=c;
      i=j-1;
  }
  return r;
}    