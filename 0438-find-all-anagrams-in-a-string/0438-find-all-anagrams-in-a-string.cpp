class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> freqP(26, 0);

        vector<int> freqWindow(26, 0);
        for (char ch : p) {
            freqP[ch - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            freqWindow[s[right] - 'a']++;
            if (right - left + 1 == p.length()) {
                if (freqWindow == freqP) {
                    ans.push_back(left);
                }
                freqWindow[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};