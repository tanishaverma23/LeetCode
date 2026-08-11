class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1=0;
        for(int i=0;i<nums.size();i++){
             sum1+=nums[i];
        }
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            while(num!=0){
                int dig=num%10;
                sum2+=dig;
                num=num/10;
            }
        }
        return abs(sum1-sum2);
    }
};