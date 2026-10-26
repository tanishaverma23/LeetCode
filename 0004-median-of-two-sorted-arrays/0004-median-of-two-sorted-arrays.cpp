class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> nums;
        for (int num : nums1) {
            nums.push_back(num);
        }
        for (int num : nums2) {
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());
        double ans=0;


        int low = 0;
        int high = nums.size() - 1;

        int mid = low + (high - low) / 2;
        int n=nums.size();
        if(n%2==0){
            ans=(double)(nums[mid]+nums[mid+1])/2.0;
        }else{
            ans=nums[mid];
        }
        return ans;
    }
};