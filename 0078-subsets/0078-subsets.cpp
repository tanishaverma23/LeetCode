class Solution {
private:
    void generateall(vector<int>& nums,int index,vector<int>curr,vector<vector<int>>& res){
        if(index==nums.size()){
           res.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        generateall(nums,index+1,curr,res);
         curr.pop_back();

        generateall(nums, index + 1, curr, res);

    }
    
public:
     vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        generateall(nums,0,curr,res);
        return res;


    
    //BIT MANIPULATION
    // int n=nums.size();
    // int subset= 1<<n;
    // vector<vector<int>>ans;
    // for(int i=0;i<subset;i++){
    //     vector<int>list;
    //     for(int j=0;j<n;j++){
    //         if(i & (1<<j)){
    //             list.push_back(nums[j]);
    //         }
    //     }
    //      ans.push_back(list);
    // }
    // return ans;
   
     


    //RECURSION
   // private:
//void solve(vector<int>nums,vector<int>output,int index, vector<vector<int> > &ans){
//     //base case
//     if(index>=nums.size()){
//         ans.push_back(output);
//         return;
//     }
//     //excclude
//     solve(nums,output,index+1,ans);
//     //include
//     int element=nums[index];
//     output.push_back(element);
//     solve(nums,output,index+1,ans);
// }    

// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>output;
//         int index=0;
//         solve(nums,output,index,ans);
//         return ans;
        
    }
};