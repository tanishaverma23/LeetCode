class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int low=0;
        int high=x;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(mid==0 || mid<=x/mid){
                ans=mid;
                low=mid+1;
            }else if(mid>x/mid){
                high=mid-1;

            }
        }
        return ans;
    }
};