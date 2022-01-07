class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n=a.size();
        int fl=0;
        for(int i=1;i<n;i++)if(a[i]<a[i-1]){
            fl=1;
            break;
        }
        if(fl==0)return 0;
        fl=0;
        for(int i=n-2;i>=0;i--)if(a[i]<a[i+1]){
            fl=1;
            break;
        }
        if(fl==0)return 0;
        int mx=0;
        for(int i=1;i<n-1;i++){
            int j=i-1,c=0;
            while(j>=0&&a[j]<a[j+1])j--;
            c+=i-j;
            j=i+1;
            while(j<n&&a[j]<a[j-1])j++;
            if(j-i-1==0||c==1)c=0;
            else c+=j-i-1;
            mx=max(mx,c);
        }
        if(mx==1)mx=0;
        return mx;
    }
};