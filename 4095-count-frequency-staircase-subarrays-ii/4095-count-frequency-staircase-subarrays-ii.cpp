class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int mx = 1; 
        int n = nums.size(); 
        while(mx * (mx + 1) <= 2 * n) mx++; 
        
        // Use static arrays to avoid heavy vector allocation overhead per test case
        static int freq[100005] = {0}; 
        static int reqFreq[100005] = {0}; 
        int ans = 0;  

        for(int i = 0; i < n; i++) {
            int dis = 0;
            int matched = 0; 
            int processed = 0; 
            for(int j = i; j < n; j++) {
                int x = nums[j]; 
                if(freq[x] == 0) {
                    dis++; 
                    if(dis > mx) break; 
                    reqFreq[x] = dis; 
                }
                freq[x]++; 
                processed = j; 
                if(freq[x] > reqFreq[x]) break;  
                if(freq[x] == reqFreq[x]) matched++; 
                if(matched == dis) ans++; 
            }
            // reset from i ... processed 
            for(int j = i; j <= processed; j++) {
                freq[nums[j]] = 0; 
            }
        }
        return ans; 
    }
};