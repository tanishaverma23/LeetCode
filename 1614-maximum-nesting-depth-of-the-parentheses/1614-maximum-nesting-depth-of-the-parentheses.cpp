class Solution {
public:
    int maxDepth(string s) {
        int i=0;
        int depth=0;
        int max_d=0;
        while(i<s.length()){
             if(s[i]=='('){
                depth++;
             }
             else if(s[i]==')'){
                max_d=max(depth,max_d);
                depth--;
             }
             i++;
        }
        return max_d;
    }
};