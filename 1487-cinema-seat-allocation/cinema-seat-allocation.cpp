class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                reserved[row] |= (1 << col);
            }
        }

        int ans = 2 * (n - reserved.size());

        for (auto &entry : reserved) {
            int mask = entry.second;

            bool left = true;
            for (int i = 2; i <= 5; i++) {
                if (mask & (1 << i))
                    left = false;
            }

            bool right = true;
            for (int i = 6; i <= 9; i++) {
                if (mask & (1 << i))
                    right = false;
            }

            bool middle = true;
            for (int i = 4; i <= 7; i++) {
                if (mask & (1 << i))
                    middle = false;
            }

            if (left && right)
                ans += 2;
            else if (left || right || middle)
                ans += 1;
        }

        return ans;
    }
};