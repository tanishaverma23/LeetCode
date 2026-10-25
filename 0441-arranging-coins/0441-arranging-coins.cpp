class Solution {
public:
    int arrangeCoins(int n) {
        int cnt=1;
        int num=n;
        for(int i=1;i<=n;i++){
            num=num-i;
             if(num>=i+1){
                cnt++;
             }else{
                break;
             }
        }
        return cnt;
    }
};