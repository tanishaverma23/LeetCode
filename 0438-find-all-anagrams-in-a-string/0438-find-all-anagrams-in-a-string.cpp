class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int psize=p.size();
        vector<int>freq(26,0);
        for(int i=0;i<psize;i++){
            freq[p[i]-'a']++;
        }
        int k=p.size();
        int left=0;
        vector<int>cnt;
        vector<int>window(26,0);
        for(int right=0;right<s.size();right++){
           window[s[right]-'a']++;

            if(right-left+1 >k){
                 window[s[left]-'a']--;
                 left++;
            }
            if(freq==window){
                cnt.push_back(left);
            }

        }
        return cnt;
    }
};