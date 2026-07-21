class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int initialOnes = 0;

        for (char ch : s) {
            if (ch == '1') {
                initialOnes++;
            }
        }

        string t = "1" + s + "1";

        vector<pair<char, int>> blocks;

        int count = 1;

        for (int i = 1; i < t.size(); i++) {

            if (t[i] == t[i - 1]) {
                count++;
            } else {
                blocks.push_back({t[i - 1], count});
                count = 1;
            }
        }

        blocks.push_back({t.back(), count});

        int ans = initialOnes;

        for (int i = 1; i + 1 < blocks.size(); i++) {

            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                int gain = blocks[i - 1].second +
                           blocks[i + 1].second;

                ans = max(ans, initialOnes + gain);
            }
        }

        return ans;
    }
};