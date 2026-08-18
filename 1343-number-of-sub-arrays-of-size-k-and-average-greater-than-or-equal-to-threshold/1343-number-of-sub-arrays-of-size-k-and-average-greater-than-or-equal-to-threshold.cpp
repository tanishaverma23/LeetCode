class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int left=0;
        int ans=0;
        int sum=0;
        for(int right=0;right<n;right++){
              sum+=arr[right];
              while(right-left+1>k){
                sum=sum-arr[left];
                left++;
              }
              if(right-left+1==k && sum/k>=threshold){
                ans++;
              }
        }
        return ans;
    }
};