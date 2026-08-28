class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        char mid = 0;
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        if (n % 2)
            cnt[mid - 'a']--;

        int h = n / 2;
        string left;

        for (int i = 0; i < h; i++) {
            int x = target[i] - 'a';

            if (cnt[x] >= 2) {
                cnt[x] -= 2;
                left += target[i];
            } 
            else {
                for (int y = x + 1; y < 26; y++) {
                    if (cnt[y] >= 2) {
                        cnt[y] -= 2;
                        left += char('a' + y);

                        for (int z = 0; z < 26; z++) {
                            while (cnt[z] >= 2) {
                                cnt[z] -= 2;
                                left += char('a' + z);
                            }
                        }

                        string ans = left;

                        if (n % 2)
                            ans += mid;

                        string rev = left;
                        reverse(rev.begin(), rev.end());
                        ans += rev;

                        return ans;
                    }
                }

                break;
            }
        }

        if ((int)left.size() == h) {
            string ans = left;

            if (n % 2)
                ans += mid;

            string rev = left;
            reverse(rev.begin(), rev.end());
            ans += rev;

            if (ans > target)
                return ans;
        }

        while (!left.empty()) {
            int cur = left.back() - 'a';
            left.pop_back();
            cnt[cur] += 2;

            int pos = left.size();

            for (int x = cur + 1; x < 26; x++) {
                if (cnt[x] < 2)
                    continue;

                cnt[x] -= 2;
                left.push_back('a' + x);

                for (int z = 0; z < 26; z++) {
                    while (cnt[z] >= 2) {
                        cnt[z] -= 2;
                        left.push_back('a' + z);
                    }
                }

                string ans = left;

                if (n % 2)
                    ans += mid;

                string rev = left;
                reverse(rev.begin(), rev.end());
                ans += rev;

                return ans;
            }
        }

        return "";
    }
};