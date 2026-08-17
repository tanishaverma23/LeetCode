class Solution {
public:
    int maxVowels(string s, int k) {

        int n = s.size();
        int ans = 0;
        int vcount = 0;
        int left = 0;
        int window = 0;

        for (int right = 0; right < n; right++) {

            if (s[right] == 'a' || s[right] == 'e' || s[right] == 'i' ||
                s[right] == 'o' || s[right] == 'u') {
                vcount++;
            }
            window++;
            
  

            while (window > k) {
                if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                    s[left] == 'o' || s[left] == 'u') {
                    vcount--;
                }
                left++;
                window--;
            }
            if(window==k){
                ans=max(ans,vcount);
             
            }
        }
        return ans;
    }
};