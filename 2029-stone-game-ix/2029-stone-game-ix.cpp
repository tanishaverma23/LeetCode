class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        // cnt[0] = number of stones whose value % 3 == 0
        // cnt[1] = number of stones whose value % 3 == 1
        // cnt[2] = number of stones whose value % 3 == 2

        int cnt[3] = {0};

        for(int x : stones) {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];


        /*
            IMPORTANT:

            Alice cannot start with a remainder-0 stone.

            Why?

            Initially sum = 0.

            If Alice takes a stone with remainder 0:

                0 + 0 = 0

            The sum is divisible by 3, so Alice loses immediately.

            Therefore, Alice must start with either:
                remainder 1
                OR
                remainder 2
        */


        /*
            CASE 1:
            Number of remainder-0 stones is EVEN.

            Remainder-0 stones do not change the sum % 3.

            They basically act like "extra moves".

            If zero is even, these 0-stones don't change
            who ultimately gets the bad position.

            So Alice wins if she has BOTH types:

                at least one remainder-1 stone
                AND
                at least one remainder-2 stone

            Example:

                stones = [1, 2]

                one = 1
                two = 1
                zero = 0 (even)

                Alice can take 1.
                Bob has to take 2.
                1 + 2 = 3
                Bob loses.

            Therefore Alice wins.
        */

        if(zero % 2 == 0) {

            if(one > 0 && two > 0) {
                return true;
            }

            return false;
        }


        /*
            CASE 2:
            Number of remainder-0 stones is ODD.

            Now the zero stones change whose turn gets
            the important position.

            Alice can win only when the numbers of
            remainder-1 and remainder-2 stones are
            sufficiently different.

            The difference must be MORE than 2.

            Example:

                one = 5
                two = 2

                abs(5 - 2) = 3

                3 > 2  -> Alice wins.

            But:

                one = 3
                two = 2

                abs(3 - 2) = 1

                1 > 2 -> false

                Alice loses.
        */

        if(abs(one - two) > 2) {
            return true;
        }

        return false;
    }
};


















