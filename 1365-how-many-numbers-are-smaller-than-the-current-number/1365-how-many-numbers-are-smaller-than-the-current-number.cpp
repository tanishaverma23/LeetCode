class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) { //1,2,2,3
    vector<int>count(nums.size());
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]<nums[i])cnt++;
            }
           count[i]=cnt;
        }
        return count;
    }
};