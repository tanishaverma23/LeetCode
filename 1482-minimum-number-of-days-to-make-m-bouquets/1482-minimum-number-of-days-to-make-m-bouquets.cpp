class Solution {
    bool is_sufficient(vector<int>& bloomDay,long long days, int m, int k){
        long long possible=0;
        long long cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                cnt++;
                if(cnt==k){
                    possible++;
                    cnt=0;
                }
            }else{
                cnt=0;
            }

        }
        if(possible<m)return false;

        return true;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k)
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        
        long long ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (is_sufficient(bloomDay, mid, m, k)) {
                ans = mid;
                high=mid-1;
            }else{
                low = mid + 1;
                
            }
        }
        return ans;
    }
};