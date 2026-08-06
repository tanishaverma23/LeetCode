// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    int solve(int low,int high,int& ans){
       
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isBadVersion(mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
public:
    int firstBadVersion(int n) {
        int ans;
        return solve(1,n,ans);
      
    }
};