class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int left=0;
        unordered_map<char,int>freq;
        int ans=0;
        for(int right=0;right<len;right++){
            freq[s[right]]++;
           
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
                
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};