class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int n=m.length();
        int l=0,r=n-1;
        //finding peak
        while(l<r){
            int mid=l+(r-l)/2;
            if(m.get(mid-1)<m.get(mid)){
                l=mid+1;
            }else r=mid;
        }
        int peak=l;
        // search in left
        l=0,r=peak;
        while(l<=r){
            int mid=l+(r-l)/2;
            int h=m.get(mid);
            if(h<target){
                l=mid+1;
            }else if(h>target)r=mid-1;
            else return mid;
        }
        //search in right
        l=peak;
        r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int h=m.get(mid);
            if(h<target){
                r=mid-1;
            }else if(h>target)l=mid+1;
            else return mid;
        }
        return -1;
    }
};