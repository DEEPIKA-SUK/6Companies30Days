#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    void func(string &s,string &r,int k,int n,int i){
        if(s>r){
            r=s;
        }
        if(k==0||i==n)return;
        char ch=s[i];
        for(int h=i+1;h<n;h++){
            ch=max(ch,s[h]);
        }
        if(s[i]!=ch)k--;
        for(int j=n-1;j>=i;j--){
            if(s[j]==ch){
                swap(s[j],s[i]);
                func(s,r,k,n,i+1);
                swap(s[j],s[i]);
            }
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string s, int k)
    {
       // code here.
       int n=s.length();
       string r=s;
       func(s,r,k,n,0);
       return r;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends