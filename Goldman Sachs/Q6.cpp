class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1.length()>=s2.length()){
            swap(s1,s2);
        }
        string r="";
        for(int i=0;i<s1.length();i++){
            if(s1.length()%(i+1)==0&&s2.length()%(i+1)==0){
                string h=s1.substr(0,i+1);
                string z="",b="";
                for(int j=0;j<(s1.length()/(i+1));j++){
                    z+=h;
                }
                for(int j=0;j<(s2.length()/(i+1));j++){
                    b+=h;
                }
                if(z==s1&&b==s2)r=h;
            }
        }
        return r;
    }
};