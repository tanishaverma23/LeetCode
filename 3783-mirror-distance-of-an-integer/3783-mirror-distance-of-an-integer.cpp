class Solution {
public:
    int mirrorDistance(int n) {
        int orig=n;
        int x=0;
        while(n!=0){
             int dig=n%10;
             x=x*10+dig;
             n/=10;
        }
        return abs(orig-x);
        
    }
};