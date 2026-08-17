class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string w;

        while (ss >> w)
            words.push_back(w);

        if (pattern.size() != words.size())
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> used;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];

            if (mp.count(c) && mp[c] != words[i])
                return false;

            if (!mp.count(c) && used.count(words[i]))
                return false;

            mp[c] = words[i];
            used[words[i]] = c;
        }

        return true;
    }
};