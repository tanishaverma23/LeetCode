class Solution {
    bool is_suffecient(vector<int>& piles,int speed, int h){
        long long hours=0;
        for(auto& pile:piles){
            hours+=(pile+speed-1)/speed;
        }

        return hours<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;

        while(low<=high){
            int mid= low+(high-low)/2;

            if(is_suffecient(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};