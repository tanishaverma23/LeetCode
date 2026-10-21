class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end()))return 0;

        string temp = s;
        sort(temp.begin(), temp.end());
        char mn = temp[0];
        char mx = temp[temp.length() - 1];

        if(s[0]==mn || s[s.length()-1]==mx)return 1;
        
        bool no_mn=true;
        bool no_mx=true;

        for(int i=0;i<s.length()-1;i++){
            if(s[i]==mn){
                no_mn=false;
                break;
            }
        }
        
         for(int i=1;i<s.length();i++){
            if(s[i]==mx){
                no_mx=false;
                break;
            }
        }

        if (s.length() <= 2) {
            return -1;
        }
         

         if(no_mn== true && no_mx==true){
            return 3;
         }else{
            return 2;
         }

    return -1;


    }
};