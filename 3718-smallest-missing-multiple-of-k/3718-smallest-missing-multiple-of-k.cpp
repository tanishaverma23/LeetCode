class Solution {
public:
    int missingMultiple(vector<int>& nums, int k){
        for(int i=1; ;i++){
            if(find(nums.begin(),nums.end(),i*k)==nums.end()){
                return i*k;
            }

        }

     return 0;
        
    }
};