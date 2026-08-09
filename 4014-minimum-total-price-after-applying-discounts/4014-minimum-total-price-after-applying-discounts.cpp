class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        double ans=0;
        int j=discounts.size()-1;
        for(int i=prices.size()-1;i>=0;i--){
            int dis=0;
             if(j>=0){
                 dis=discounts[j];
                 j--;
             }
             ans+=(double)prices[i] *(100-dis)/100;
        } 
        return ans;
    }
};