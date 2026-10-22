class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }
        bool inc = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                inc = false;
                break;
            }
        }
        bool dec = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != (n - i) % n) {
                dec = false;
                break;
            }
        }
        if (!inc && !dec) return -1;

        if (inc) {
            int rotate = pos;
            int alternative = 2 + (n - pos) % n;
            return min(rotate, alternative);
        }
        int reverseFirst = 1 + (n - 1 - pos + n) % n;
        int rotateFirst = 1 + (pos + 1) % n;
        return min(reverseFirst, rotateFirst);
    }
};