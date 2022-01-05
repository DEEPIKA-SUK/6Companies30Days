class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }else{
                string r="";
                while(!st.empty()&&st.top()!='['){
                    r=st.top()+r;
                    st.pop();
                }
                st.pop();
                string c="";
                while(!st.empty() && (st.top()-'0')>=0 && (st.top()-'0')<=9){
                    c=st.top()+c;
                    st.pop();
                }
                int x = stoi(c);
                while(x--){
                    for(int j=0;j<r.length();j++)st.push(r[j]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};