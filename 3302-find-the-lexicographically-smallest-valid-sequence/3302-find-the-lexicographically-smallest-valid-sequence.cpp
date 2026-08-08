class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        vector<int> next(n + 1, 0);

        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {

            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            next[i] = m - 1 - j;
        }

        vector<int> ans;
        int pos = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < n && pos < m; i++) {

            if (word1[i] == word2[pos]) {
                ans.push_back(i);
                pos++;
            }
            else {
                if (!mismatchUsed) {
                    if (next[i + 1] >= m - pos - 1) {

                        ans.push_back(i);

                        mismatchUsed = true;
                        pos++;
                    }
                }
            }
        }
        if (ans.size() != m) {
            return {};
        }

        return ans;
    }
};