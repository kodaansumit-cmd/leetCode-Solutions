class Solution {
public:
    vector<int> countDigits(int n) {
        vector<int> cnt(10, 0);

        while (n > 0) {
            cnt[n % 10]++;
            n /= 10;
        }

        return cnt;
    }

    bool isSame(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 10; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> target = countDigits(n);

        for (int power = 1; power <= 1000000000; power *= 2) {
            vector<int> current = countDigits(power);

            if (isSame(target, current))
                return true;
        }

        return false;
    }
};