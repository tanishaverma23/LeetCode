class Solution {
    int helper(string date) {
        vector<int> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> pref(days.size(), 0);

        pref[0] = days[0];
        for (int i = 1; i < days.size(); i++) {
            pref[i] = pref[i - 1] + days[i];
        }
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int ans = (month == 1) ? day : pref[month - 2] + day;

        return ans;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int arrive_A = helper(arriveAlice);
        int arrive_B = helper(arriveBob);
        int leave_A = helper(leaveAlice);
        int leave_B = helper(leaveBob);

        int startTogether = max(arrive_A, arrive_B);
        int endTogether = min(leave_A, leave_B);

        return (startTogether > endTogether) ? 0
                                             : endTogether - startTogether + 1;
    }
};