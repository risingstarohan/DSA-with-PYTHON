class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};

        for (int d : digits)
            cnt[d]++;

        int ans = 0;

        for (int num = 100; num <= 998; num++) {
            if (num % 2 != 0)
                continue;

            int x = num;

            int a = x / 100;        // hundreds
            int b = (x / 10) % 10; // tens
            int c = x % 10;        // units

            // Check digit availability
            cnt[a]--;
            cnt[b]--;
            cnt[c]--;

            if (cnt[a] >= 0 && cnt[b] >= 0 && cnt[c] >= 0)
                ans++;

            // Restore counts
            cnt[a]++;
            cnt[b]++;
            cnt[c]++;
        }

        return ans;
    }
};
