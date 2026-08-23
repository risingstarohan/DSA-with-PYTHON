class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), diff = 0, q = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                q++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                q--;
            else
                diff -= num[i] - '0';
        }

        if ((q & 1) != 0)
            return true;

        return diff != -(q / 2) * 9;
    }
};