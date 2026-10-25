class Solution {
    int help(int num){
        int count=0;
        while(num>0){
            count+=num&1;
            num=num>>1;
        }
        return count;
    }
public:
    int calculateScore(int a, int b) {
        int s1=help(a);
        int s2=help(b);

        if(s1>=s2)return s1*s2;

        return s2/s1;
    }
};