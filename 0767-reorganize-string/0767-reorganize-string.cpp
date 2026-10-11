class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }
        int maxFreq = 0, ch = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                ch = i;
            }
        }
        if (maxFreq > (n + 1) / 2) {
            return "";
        }
        string ans(n, ' ');
        int idx = 0;

        while (freq[ch] > 0) {
            ans[idx] = char(ch + 'a');
            idx += 2;
            freq[ch]--;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (idx >= n) {
                    idx = 1;
                }
                ans[idx] = char(i + 'a');
                idx += 2;
                freq[i]--;
            }
        }
        return ans;
    }
};