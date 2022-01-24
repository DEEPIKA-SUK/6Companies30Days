class Solution {
public:
    bool func(vector<int> &piles, int mid, int h){
        int t = 0;
        for (int x:piles){
            t+=ceil((long double)x/mid);
        }
        return t<=h; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = INT_MAX;
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l<=r){
            int mid = l + (r-l )/ 2;
            if (func(piles, mid, h)){
                ans = mid;
                r = mid - 1;
            }
            else l=mid+1;
        }
        return ans;
    }
};