class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int indG = -1;
        int indP = -1;
        int indM = -1;
        bool g = false;
        bool p = false;
        bool m = false;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = garbage[i].size() - 1; j >= 0; j--) {
                if (garbage[i][j] == 'G' && g == false) {
                    indG = i;
                    g = true;
                }
                if (garbage[i][j] == 'P' && p == false) {
                    indP = i;
                    p = true;
                }
                if (garbage[i][j] == 'M' && m == false) {
                    indM = i;
                    m = true;
                }
            }
        }
        int sumG = 0;
        int sumP = 0;
        int sumM = 0;
        for (int i = 0; i < indG; i++) {
            sumG += travel[i];
        }
        for (int i = 0; i < indP; i++) {

            sumP += travel[i];
        }
        for (int i = 0; i < indM; i++) {
            sumM += travel[i];
        }
        for (int i = 0; i < garbage.size(); i++) {
            for (int j = 0; j < garbage[i].size(); j++) {
                if (garbage[i][j] == 'G') {
                    sumG++;
                }
                if(garbage[i][j]=='P'){
                    sumP++;
                }
                if(garbage[i][j]=='M'){
                    sumM++;
                }
            }
        }
        return sumP+sumG+sumM;
    }
};