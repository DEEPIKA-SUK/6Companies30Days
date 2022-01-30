class Solution {
public:
    bool winnerOfGame(string s) {
        int c1=0,c2=0,c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='A')c++;
            else{
                if(c>=3)c1+=c-2;
                c=0;
            }
        }
        if(c>=3)c1+=c-2;
        c=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='B')c++;
            else{
                if(c>=3)c2+=c-2;
                c=0;
            }
        }
        if(c>=3)c2+=c-2;
        if(c1>c2)return 1;
        return 0;
    }
};