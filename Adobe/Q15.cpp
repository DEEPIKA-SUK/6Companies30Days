#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)

int main() {
    string s1,s2;
    cin>>s1>>s2;
    ll n1=s1.length(),n2=s2.length(),i=0,j=0;
    string r1="",r2="";
    ll fl=0;
    while(i<n1&&j<n2){
        while(i<n1&&s1[i]!='.'){
            r1+=s1[i];
            i++;
        }
        while(j<n2&&s2[j]!='.'){
            r2+=s2[j];
            j++;
        }
        if(stoll(r1)>stoll(r2)){
            cout<<s1<<endl;
            fl=1;
            break;
        }else if(stoll(r1)<stoll(r2)){
            cout<<s2<<endl;
            fl=1;
            break;
        }
        r1="";
        r2="";
        i++;
        j++;
    }
    if(fl==0){
        if(i<n1&&j>=n2)cout<<s1<<endl;
        else if(j<n2&&i>=n1)cout<<s2<<endl;
        else cout<<"Equal";
    }
}