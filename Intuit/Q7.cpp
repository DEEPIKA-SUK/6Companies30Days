class Solution {
public:
    bool func(int mid,vector<int>& nums,int m){
        int c=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>mid)
                return false;
            if(c+nums[i]<=mid)
                c+=nums[i];
            else{
                sum++;
                c=nums[i];
            }
        }
        sum++;
        return sum<=m;
    }
    int shipWithinDays(vector<int>& nums, int m) {
        int r=0;
        for(int i=0;i<nums.size();i++)r+=nums[i];
        if(m==1)return r;
        int l=0;
        while(l<r){
            int mid=(l+r)/2;
            if(func(mid,nums,m))
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};