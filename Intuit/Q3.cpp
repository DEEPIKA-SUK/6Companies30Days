#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
long long func(string r){
    long long n=0;
    for(int i=0;i<r.size();i++)n=n*10+r[i]-'0';
    return n;
}
int missingNumber(const string& s)
{
    // Code here
    int n=s.size();
    for(int length=1;length<=6;length++){
       string r="";
       int l=length,i=0;
       while(i<s.size()&&l--)r+=s[i++];
       long long prev=func(r),c=0,j=i,missing,fl=0;
       r="";
       while(j<s.size()){
               r+=s[j++];
               if(prev+1==func(r)){
                   prev=func(r);
                   r="";
               }
               else if(prev+2==func(r)){
                    c++;
                    missing=prev+1;
                    prev=func(r);
                    r="";
                }
                else if(prev<func(r))fl=1;
        }
        if(c==1&&fl==0)return missing;
    }
    return -1;
}