class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int freq[26] = {};

        for (char c : s)
            freq[c - 'a']++;

        int odd = 0, mid = -1;

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        for (int i = 0; i < 26; i++)
            freq[i] /= 2;

        int half = n / 2;
        string ans(n, 'a');

        auto makePalindrome = [&]() {
            if (mid != -1)
                ans[half] = char('a' + mid);

            for (int i = 0; i < half; i++)
                ans[n - 1 - i] = ans[i];
        };

        int pos = 0;

        // Match target's left half as much as possible
        while (pos < half) {
            int c = target[pos] - 'a';

            if (freq[c] == 0)
                break;

            ans[pos] = target[pos];
            freq[c]--;
            pos++;
        }

        // The exact left half is possible
        if (pos == half) {
            makePalindrome();

            if (ans > target)
                return ans;
        }

        // Find the smallest possible increase
        while (true) {
            if (pos < half) {
                int need = target[pos] - 'a' + 1;

                for (int c = need; c < 26; c++) {
                    if (freq[c] == 0)
                        continue;

                    ans[pos] = char('a' + c);
                    freq[c]--;

                    int idx = pos + 1;

                    for (int x = 0; x < 26; x++) {
                        while (freq[x] > 0) {
                            ans[idx++] = char('a' + x);
                            freq[x]--;
                        }
                    }

                    makePalindrome();
                    return ans;
                }
            }

            if (pos == 0)
                return "";

            pos--;
            freq[target[pos] - 'a']++;
        }
    }
};