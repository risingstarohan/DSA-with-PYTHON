class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        for (int i = 1; ; i++) {
            int multiple = i * k;

            if (!st.count(multiple)) {
                return multiple;
            }
        }
    }
};