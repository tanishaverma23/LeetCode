class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int num=n;
        int prod=1;
        while(num!=0){
            int dig=num%10;
            sum+=dig;
            prod*=dig;
            num=num/10;
        }

        int total=sum+prod;
        if(n%total==0){
            return true;
        }
        return false;
        
    }
};