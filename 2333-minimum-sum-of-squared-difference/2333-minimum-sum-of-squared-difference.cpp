class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        

        int maxDiff = 0;
        vector<long long> diffCount(100001, 0);
        
        long long totalDiff = 0;
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            diffCount[d]++;
            maxDiff = max(maxDiff, d);
            totalDiff += d;
        }
        
        
        if (k >= totalDiff) return 0;
        
        
        for (int i = maxDiff; i > 0 && k > 0; --i) {
            if (diffCount[i] == 0) continue;
            
           
            long long take = min(k, diffCount[i]);
            diffCount[i] -= take;
            diffCount[i - 1] += take;
            k -= take;
        }
        
       
        long long ans = 0;
        for (int i = 1; i <= maxDiff; ++i) {
            if (diffCount[i] > 0) {
                ans += diffCount[i] * (long long)i * i;
            }
        }
        
        return ans;
    }
};