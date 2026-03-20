class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> used;

        int i = 0, n = s.size();

        for (char c : pattern) {
            if (i >= n) return false;

            int j = i;
            while (j < n && s[j] != ' ') j++;

            string word = s.substr(i, j - i);

            if (mp.count(c)) {
                if (mp[c] != word) return false;
            } else {
                if (used.count(word)) return false;
                mp[c] = word;
                used.insert(word);
            }

            i = j + 1;
        }

        return i > n;
    }
};