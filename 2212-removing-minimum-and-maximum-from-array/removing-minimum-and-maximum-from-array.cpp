class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();

        int a = max(mn, mx) + 1;
        int b = n - min(mn, mx);
        int c = min(mn, mx) + 1 + n - max(mn, mx);

        return min({a, b, c});
    }
};