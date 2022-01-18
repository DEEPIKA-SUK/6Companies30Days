 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int n=str.length();
        int c=0,p=1;
        for(int i=n-1;i>=0;i--){
            int x=str[i]-'0';
            if((str[i]!='-'&&(x<0||x>9))||(str[i]=='-'&&i!=0))return -1;
            else if(i!=0){
                c+=p*x;
                p*=10;
            }else if(i==0&&str[i]=='-'){
                c*=-1;
            }else if(i==0){
                c+=p*x;
                p*=10;
            }
        }
        return c;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends