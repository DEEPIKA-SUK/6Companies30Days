class Solution {
public:
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        int m = 1e9+7;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({e[i],s[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        multiset<int> st;
        long long t = 0,h=0;
        for(int i=0;i<n;i++){
            st.insert(v[i].second);
            h+= v[i].second;
            t = max(t,h*v[i].first);
            if(st.size() == k){
                h -= *st.begin();
                st.erase(st.begin());
            }
        }
        return (t%m);
    }
};