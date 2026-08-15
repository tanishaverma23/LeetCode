class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int>,vector<string>>mpp;
       
        for(int i=0;i<strs.size();i++){
             vector<int>help(26,0);
            for(int j=0;j<strs[i].size();j++){
                help[strs[i][j]-'a']++;
            }
            mpp[help].push_back(strs[i]);
        }
        for(auto& it:mpp){
            ans.push_back(it.second);
        }
         return ans;
    }
};
