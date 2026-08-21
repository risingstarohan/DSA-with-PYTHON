class Solution {
public:
    using ll = long long;

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());

        vector<int> c;

        for (int coin : coins) {
            bool useful = true;

            for (int x : c) {
                if (coin % x == 0) {
                    useful = false;
                    break;
                }
            }

            if (useful) c.push_back(coin);
        }

        coins = c;
        int n = coins.size();

        auto count = [&](ll x) -> ll {
            ll total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                ll lcm = 1;
                int bits = 0;
                bool overflow = false;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        ll g = gcd(lcm, (ll)coins[i]);

                        if (lcm > x / (coins[i] / g)) {
                            overflow = true;
                            break;
                        }

                        lcm = lcm / g * coins[i];
                    }
                }

                if (overflow || lcm > x) continue;

                if (bits % 2 == 1)
                    total += x / lcm;
                else
                    total -= x / lcm;
            }

            return total;
        };

        ll low = 1;
        ll high = 1LL * coins[0] * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};