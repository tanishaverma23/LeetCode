#include <vector>
#include <cmath>

class Solution {
public:
    int minQueenMoves(std::vector<int>& source, std::vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];

       
        if (sr == tr && sc == tc) {
            return 0;
        }

      
        if (sr == tr || sc == tc || std::abs(sr - tr) == std::abs(sc - tc)) {
            return 1;
        }

    
        return 2;
    }
};