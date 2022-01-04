#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        string r="";
        stack<int> st;
        int num=1;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='D'){
                st.push(num);
                num++;
            }else{
                st.push(num);
                num++;
                while(!st.empty()){
                    char g=st.top()+'0';
                    r+=g;
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty()){
            char g=st.top()+'0';
            r+=g;
            st.pop();
        }
        return r;
    }
};